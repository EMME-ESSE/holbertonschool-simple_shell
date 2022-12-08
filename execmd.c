#include "main.h"

/**
 * execmd - attempts to run a program
 *
 * @argv: name of program to execute
 *
 * Return: 0
 *
 * Description: execmd will automatically look for programs in every folder
 * defined within the $PATH variable, one by one. The max size of the PATH
 * variable is currently 256 bytes (PATBUFF 256)
 * The max size for the command is currently 128 bytes. (COMBUFF 128)
 */
int execmd(char **argv)
{
	pid_t pid;
	/**This var will check if child is finished to call exit*/
	int status;
	char *rawPathz = NULL, *pathz[PATBUFF], newpath[COMBUFF];
	int i;

	pid = fork();

	if (pid == 0)
	{/**get $PATH and tokenize */
		rawPathz = _getenv("PATH");
		*pathz = strtok(rawPathz, ":");
		for (; *pathz != NULL ;)
		{/**check if program is in any of the PATHs */
			for (i = 0; i < COMBUFF; i++)
				newpath[i] = 0;
			strcpy(newpath, *pathz); /**build path */
			strcat(newpath, "/");
			strcat(newpath, argv[0]); /**add arg and exec */
			execve((const char *)newpath, argv, NULL);
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
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(rawPathz);
	return (0);
}
