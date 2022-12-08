#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int _strcmp(char *, char *);

int main()
{
    int i = 0;
    extern char **environ;

    printf("Environment variables:\n");

    while (environ[i++])
	    if (_strcmp(environ[i], "HOME") == '=')
		    break;
	    else if (environ[i] == NULL)
		    perror("Error");
        printf("envp[%d]: %s\n", i, environ[i]);
    return (0);
}



int _strcmp(char *s1, char *s2)
{
        int a = 0;

        while (s1[a] == s2[a])
        {
                if (s1[a] == '\0' || s2[a] == '\0')
                        break;
                a++;
        }
        if (s1[a] == '\0' && s2[a] == '\0')
                return (0);
        else
                return (s1[a] - s2[a]);
}
