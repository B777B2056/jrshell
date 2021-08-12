#include "../inc/jrshell.h"

Command _split_single_cmd(const char* str) {
    int i = 0, j = 0, k = 0, sp = 0;
    Command cmd;
    cmd.pos = -1;
    cmd.option[0] = '\0';
    for(const char* t = str; *t != '\0'; ++t) {
        if(*t == ' ') {
            ++sp;
            continue;
        }
        switch(*t) {
            case ' ':
                ++sp;
                break;
            case '>':
            case '<':
                cmd.symbol = *t;
                cmd.pos = k;
                cmd.param[k++] = *t;
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
        } else {
            commands[cnt][i++] = *str;
        }
    }
    commands[cnt][i] = '\0';
    return ++cnt;
}

void _exec_single_cmd(Command cmd) {
    int fd;
    char* file = NULL;
    char param[PARAM_LEN];
    if(cmd.pos == -1) {
        memcpy(param, cmd.param, strlen(cmd.param));
    } else {
        memcpy(param, cmd.param, cmd.pos);
        param[cmd.pos] = '\0';
    }
    switch(fork()) {
        case -1:
            printf("%s\r\n", strerror(errno));
            break;
        case 0:
            switch(cmd.symbol) {
                case '>':
                    file = cmd.param + cmd.pos + 1;
                    fd = open(file, O_WRONLY);
                    if(fd == -1) {
                        printf("%s:%s\r\n", file, strerror(errno));
                        return;
                    }
                    dup2(fd, STDOUT_FILENO);
                    break;
                case '<':
                    file = cmd.param + cmd.pos + 1;
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
            wait(NULL);
            if(cmd.pos != -1)
                printf("Write ok.\r\n");
            break;
    }
}

void _exec_multi_cmd(const Command* cmds, int n, int i) {
    
}

void _exec_cmd(const char* str, int cn, int cl) {
    // Malloc source
    int i;
    Command* cmds = NULL;
    char** commands = (char**)malloc(cn * sizeof(char*));
    for(i = 0; i < cl; ++i)
        commands[i] = (char*)malloc(cl * sizeof(char));
    // Init each command
    int n = _split_cmds(str, commands);
    cmds = (Command*)malloc(n * sizeof(Command));
    for(i = 0; i < n; ++i) {
        cmds[i] = _split_single_cmd(commands[i]);
        /*
        printf("name:%s,option:%s,param:%s,symbol:%c\r\n", 
                cmds[i].name, cmds[i].option, cmds[i].param, cmds[i].symbol);
        */
    }
    // Exec command
    if(n == 0) {
        
    } else if(n == 1) {
        _exec_single_cmd(cmds[0]);
    } else {
        _exec_multi_cmd(cmds, n, 0);
    }
    // Release source
    free(cmds);
    for(i = 0; i < cl; ++i)
        free(commands[i]);
    free(commands);
}

