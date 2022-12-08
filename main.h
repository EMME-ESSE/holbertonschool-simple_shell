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

/** Shell functions */
int execmd(char **argv);
int __launch(char **argv);
/** Built-in functions */
int fun_cd(char **argv);
int fun_exit(char **argv);

/** Environment handlers */
char *_getenv(char *envy);

/** Strings */
int _strlen(char *string);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strncat(char *dest, char *src, int n);
char *_strcut(char *s1, char *s2);

#endif
