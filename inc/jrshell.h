#ifndef JRSHELL_H
#define JRSHELL_H

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>

#define DIR_LEN 512

/**
 * @brief split lines to command and parameters
 */
void split(const char* str, char* command, char* param);

/**
 * @brief cd command
 */
void cd(const char* directory);

/**
 * @brief clear all output in shell
 */
void clr();

/**
 * @brief show all files in the directory
 */
void ls(const char* directory);

#endif

