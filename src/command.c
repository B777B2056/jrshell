#include "../inc/command.h"

void _cd(const char* directory) {
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

void _clr() {
    
}

void _ls(const char* directory) {
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

void _echo(const char* param) {
    printf("%s\r\n", param);
}

void _pwd() {
    _cd(".");
}

void _pause() {
    fflush(stdin);
    while(getchar() != '\n');
}

void _quit() {
    exit(0);
}

