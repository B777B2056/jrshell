#include "../inc/jrshell.h"

Command _split_single_cmd(const char* str) {
    int i = 0, j = 0, k = 0, sp = 0;
    Command cmd;
    cmd.pos = -1;
    cmd.option[0] = '\0';
    for(const char* t = str; *t != '\0'; ++t) {
        switch(*t) {
            case '>':
            case '<':
                cmd.symbol = *t;
                cmd.pos = k;
                cmd.param[k++] = *t;
                break;
            case ' ':
                ++sp;
                if(k == 0)
                    break;
            default:
                switch(sp) {
                    case 0:
                        cmd.name[i++] = *t;
                        break;
                    case 1:
                        if(*t == '-')
                            cmd.option[j++] = *t;
                        else {
                            if(strlen(cmd.option) == 0) {
                                ++sp;
                                cmd.param[k++] = *t;
                            } else
                                cmd.option[j++] = *t;
                        }
                        break;
                    default:
                        cmd.param[k++] = *t;
                        break;
                }
                break;
        }
    }
    cmd.name[i] = '\0';
    cmd.option[j] = '\0';
    cmd.param[k] = '\0';
    return cmd;
}

int _split_cmds(const char* str, char** commands) {
    int i = 0, cnt = 0;
    for(; *str == ' '; ++str);
    for(; *str != '\0'; ++str) {
        if(*str == '|') {
            commands[cnt++][i-1] = '\0';
            i = 0;
            ++str;
            for(; *str == ' '; ++str);
            --str;
        } else {
            commands[cnt][i++] = *str;
        }
    }
    commands[cnt][i] = '\0';
    return ++cnt;
}

void _split_pf(Command c, int* p_end, int* f_start) {
    char* t = c.param + c.pos - 1;
    char* m = c.param + c.pos + 1;
    *p_end = c.pos - 1;
    *f_start = c.pos + 1;
    for(; *t == ' '; --t)
        --(*p_end);
    for(; *m == ' '; ++m)
        ++(*f_start);
    ++(*p_end);
}

void _exec_single_cmd(Command cmd) {
    int fd = -1;
    int p_end, f_start;
    char* file = NULL;
    char param[PARAM_LEN];
    if(cmd.pos == -1) {
        memcpy(param, cmd.param, strlen(cmd.param));
    } else {
        _split_pf(cmd, &p_end, &f_start);
        memcpy(param, cmd.param, p_end + 1);
        param[p_end] = '\0';
    }
    switch(fork()) {
        case -1:
            printf("%s\r\n", strerror(errno));
            break;
        case 0:
            switch(cmd.symbol) {
                case '>':
                    file = cmd.param + f_start;
                    printf("%s\r\n", file);
                    fd = open(file, O_WRONLY);
                    if(fd == -1) {
                        printf("%s:%s\r\n", file, strerror(errno));
                        return;
                    }
                    dup2(fd, STDOUT_FILENO);
                    break;
                case '<':
                    file = cmd.param + f_start;
                    fd = open(file, O_RDONLY);
                    if(fd == -1) {
                        printf("%s\r\n", strerror(errno));
                        return;
                    }
                    dup2(fd, STDIN_FILENO);
                    break;
            }
            if(strcmp(cmd.name, "cd") == 0) {
                _cd(strlen(param) == 0 ? "." : param);
            } else if(strcmp(cmd.name, "clr") == 0) {
                _clr();
            } else if(strcmp(cmd.name, "ls") == 0) {
                _ls(strlen(param) == 0 ? "." : param);
            } else if(strcmp(cmd.name, "pwd") == 0) {
                _pwd();
            } else if(strcmp(cmd.name, "echo") == 0) {
                _echo(param);
            } else if(strcmp(cmd.name, "pause") == 0) {
                _pause();
            } else if(strcmp(cmd.name, "quit") == 0) {
                _quit();
            } else {
                printf("%s:%s\r\n", cmd.name, "command not found");
            }
            _exit(0);
            break;
        default:
            if(fd != -1)
                close(fd);
            wait(NULL);
            break;
    }
}

void _exec_multi_cmd(Command* cmds, int n) {
    int pfd[2];
    if(pipe(pfd) == -1) {
        printf("%s\r\n", strerror(errno));
        return;
    }
    Command cmd = cmds[0];
    for(int i = 0; i < n;) {
        switch(fork()) {
            case -1:
                printf("%s\r\n", strerror(errno));
                break;
            case 0:
                dup2(pfd[1], STDOUT_FILENO);
                close(pfd[0]);
                _exec_single_cmd(cmd);
                _exit(0);
                break;
            default:
                close(pfd[1]);
                wait(NULL);
                ++i;
                if(i >= n)
                    break;
                char s[PARAM_LEN], p[ALL_LEN];
                memset(s, 0, PARAM_LEN);
                memset(p, 0, ALL_LEN);
                strcat(p, cmds[i].name);
                strcat(p, " ");
                read(pfd[0], s, PARAM_LEN);
                strcat(p, s);
                int j;
                for(j = 0; p[j] != '\0'; ++j) {
                    if(p[j] == '\r' || p[j] == '\n') {
                        p[j] = '\0';
                        break;
                    }
                }
                cmd = _split_single_cmd(p);
                close(pfd[0]);
                break;
        }
    }
    char ch;
    while(read(pfd[0], &ch, 1) > 0)
        printf("%c", ch);
    close(pfd[0]);
    close(pfd[1]);
}

void _exec_cmd(const char* str, int cn, int cl) {
    // Malloc source
    int i;
    Command* cmds = NULL;
    char** commands = (char**)malloc(cn * sizeof(char*));
    for(i = 0; i < cn; ++i)
        commands[i] = (char*)malloc(cl * sizeof(char));
    // Init each command
    int n = _split_cmds(str, commands);
    cmds = (Command*)malloc(n * sizeof(Command));
    for(i = 0; i < n; ++i) {
        cmds[i] = _split_single_cmd(commands[i]);
    }
    // Exec command
    if(n == 0) {
        
    } else if(n == 1) {
        _exec_single_cmd(cmds[0]);
    } else {
        _exec_multi_cmd(cmds, n);
    }
    // Release source
    free(cmds);
    for(i = 0; i < cn; ++i)
        free(commands[i]);
    free(commands);
}

