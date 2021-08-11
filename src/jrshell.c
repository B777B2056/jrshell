#include "../inc/jrshell.h"

void split(const char* str, char* command, char* param) {
    for(; *str == ' '; ++str);
    int flag = 0;
    for(const char* t = str; *t != '\0'; ++t) {
        if(*t == ' ') {
            ++flag;
            continue;
        }
        if(flag == 0)
            *(command++) = *t;
        else
            *(param++) = *t;
    }
    if(flag) {
        *(--param) = '\0';    // delete \n
        *command = '\0';
    } else {
        *param = '\0';    // empty param
        *(--command) = '\0';    // delete \n
    }
}

void cd(const char* directory) {
    if(chdir(directory) == -1) 
        printf("%s\r\n", strerror(errno));
    else {
        char dir[DIR_LEN];
        if(!getcwd(dir, DIR_LEN))
            printf("%s\r\n", strerror(errno));
        else
            printf("%s\r\n", dir);
    }
}

void clr() {
    
}

void ls(const char* directory) {
    DIR* d = opendir(directory); 
    if(!d) {
        printf("%s\r\n", strerror(errno));
        return;
    }
    struct dirent* dir = NULL;
    for(;;) {
        errno = 0;
        dir = readdir(d);
        if(!dir) {
            if(errno)
                printf("%s\r\n", strerror(errno));
            else 
                break;
        } else {
            printf("%s ", dir->d_name);
        }
    }
    printf("\r\n");
    closedir(d);
}

