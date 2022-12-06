#include "main.h"
<<<<<<< HEAD
void execmd(char **argv)
=======
int execmd(char **argv)
>>>>>>> e3c6ceb09262462fc343eb65f0207208432e1d8d
{		/**wpid is just here to catch the stack before its destroyed*/
	pid_t pid;
        char *command = NULL;
	/**This var will check if child is finished to call exit*/
	int status;

	/**>Fork the function first and save the PID so the parent can wait*/
	pid = fork();
	command = argv[0]; /**>This is always true */

	/** Remember fork returns twice, 1 for parent, 0 for child*/
	if (pid == 0)
	{
<<<<<<< HEAD
		if (execvp(command, argv) == -1)
=======
		if (execvp(command, argv) == -1) /** gotta change this execvp for an execve <<<<<<<<<<*/
>>>>>>> e3c6ceb09262462fc343eb65f0207208432e1d8d
			perror("42 Error: ");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0) /** If <0, something went wrong forking*/
		perror("43 Error: ");
	else /** if it isnt 0 or -1 then the parent waits for child to die*/
	{ /** use a do here so it runs once before checking */
		do {
			pid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
			/** Use the wifexited and wifsignaled to check if child
			was exited or cancelled. so parent can stop waiting*/
	}
	return (0);
}
