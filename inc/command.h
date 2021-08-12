#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>

#define DIR_LEN 512

void _cd(const char* directory);

void _clr();

void _ls(const char* directory);

void _echo(const char* param);

void _pwd();

void _pause();

void _quit();

#endif

