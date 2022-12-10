#ifndef MAIN_H
#define MAIN_H

#define CWDBUFF 128
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

extern char **environ;

/** Shell functions */
int execmd(char **argv);
int __launch(char **argv);
/** Built-in functions */
int fun_cd(char **argv);
int fun_exit(char **argv);

/** Environment handlers */
char *_getenv(char *envy);
int _setenv(char *envy, char *newValue, int op);

/** Strings */
int _strlen(char *string);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strncat(char *dest, char *src, int n);
char *_strcut(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strncmp(char *s1, char *s2, int n);

#endif
