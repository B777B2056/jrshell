#ifndef JRSHELL_H
#define JRSHELL_H

#include "command.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CMD_LEN 64
#define OP_LEN 64
#define PARAM_LEN 256

typedef struct {
    char name[CMD_LEN];
    char option[OP_LEN];
    char param[PARAM_LEN];
    char symbol;    // like <, >, etc.
    int pos;    // symbol position in param
} Command;

/**
 * @brief split single line to command and parameters
 */
Command _split_single_cmd(const char* str);

/**
 * @brief split multi command lines which are cat with '|' or '>', etc.
 */
int _split_cmds(const char* str, char** commands);

/**
 * @brief split param and file path from Command.param
 */
void _split_pf(Command c, int* p_end, int* f_start);

void _exec_single_cmd(Command cmd);

void _exec_multi_cmd(const Command* cmds, int n, int i);

/**
 * @brief exec one command
 */
void _exec_cmd(const char* str, int cn, int cl);

#endif

