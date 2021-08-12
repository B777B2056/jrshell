#include "../inc/jrshell.h"

#define CMD_NUM 32

int main(void) {
    char str[CMD_NUM * CMD_LEN];
    memset(str, 0, CMD_NUM * CMD_LEN);
    for(;;) {
        printf("%s", "user:");
        fgets(str, CMD_NUM * CMD_LEN, stdin);
        str[strlen(str) - 1] = '\0';
        _exec_cmd(str, CMD_NUM, CMD_LEN); 
    }
    return 0;
}

