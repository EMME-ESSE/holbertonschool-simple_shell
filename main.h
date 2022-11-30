#ifndef MAIN_H
#define MAIN_H

#define PROMPT "$ "
#define PROPERTY_SEPARATROR '='
#define PATH_SEPARATROR ':'
#define COMMAND_LINE_SEPARATROR "\n\t\r "
#define END_STRING_CHAR '\0'
extern char **environ;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
int exit_fun(void);
void execmd(char **argv);
#endif
