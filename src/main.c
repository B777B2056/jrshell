#include "../inc/jrshell.h"

#define COMMAND_LEN 256
#define PARAM_LEN 256

int main(void) {
    for(;;) {
        char str[COMMAND_LEN + PARAM_LEN];
        char command[COMMAND_LEN];
        char param[PARAM_LEN];
        printf("%s", "user:");
        fgets(str, COMMAND_LEN + PARAM_LEN, stdin);
        split(str, command, param);
        printf("%s", "user:");
        if(strcmp(command, "cd") == 0) {
            cd(param);
        } else if(strcmp(command, "clr") == 0) {
            clr();
        } else if(strcmp(command, "ls") == 0) {
            ls(strlen(param) == 0 ? "." : param);
        } else {
            printf("%s:%s\r\n", command, "command not found");
        }
    }
    return 0;
}

