#include "main.h"
#define BUFF 128
/**
 * execmd - attempts a system call
 *
 * args: name of program to execute
 *
 * Return: 0
 */
int execmd(char **argv)
{
	pid_t pid;
	/**This var will check if child is finished to call exit*/
	int status;
	char *rawPathz = NULL, *pathz[BUFF], newpath[BUFF];
	int i;

	pid = fork();

	if (pid == 0)
	  {/**get $PATH and tokenize */
	    rawPathz = getenv("PATH");
	    *pathz = strtok(rawPathz, ":");
	    for (;*pathz != NULL;)
	      {/**check if program is in any of the PATHs */
		for (i = 0; i < BUFF; i++)
		  newpath[i] = 0;
		strcpy(newpath, *pathz); /**build path */
		strcat(newpath, "/");
		strcat(newpath, argv[0]); /**add arg and exec */
		execve((const char*)newpath, argv, NULL);
		*pathz = strtok(NULL, ":"); /**get next PATH if exec failed*/
		if (!*pathz) /**if no path left, throw error*/
		  break;
	      }
	    perror("Error");
	    exit(EXIT_FAILURE);
	  }
	else if (pid < 0)
		perror("Error");
	else
	{ /** use a do here so it runs once before checking */
		do {
			pid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}
