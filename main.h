#ifndef MAIN_H
#define MAIN_H

#define COMBUFF 128
#define PATBUFF 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

int exit_fun(void);
int execmd(char **argv);
int fun_cd(char **argv);
int fun_env(char **);
int fun_exit(char **argv);
int __launch(char **argv);
char *_getenv(void);

#endif
