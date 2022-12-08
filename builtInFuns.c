#include "main.h"

/**
 * fun_cd - executes the chdir function with a given parameter
 *
 * @argv: argument for chdir
 *
 * Return: 0 on success, -1 on error.
 */
int fun_cd(char **argv)
{
	char *env = NULL, cwd[CWDBUFF], owd[CWDBUFF];

	/*save the cwd, add this to main to call it only once */
	getcwd(cwd, CWDBUFF);

	if (argv[1] == NULL)
	{
		env = _strcut("HOME=", _getenv("HOME"));
		if (chdir(env) != 0)
		{
			perror("Error");
			free(env);
			return (-1);
		}
		else
			free(env);
	}
	else if (_strcmp(argv[1], "-") == 0)
	{
		env = owd;
		if (chdir(env) != 0)
		{
			perror("44 Error");
			return (-1);
		}
	}
	else
	{
		if (chdir(argv[1]) != 0)
		{
			perror("Error");
			return (-1);
		}
	}
	if (_strcmp(cwd, owd) != 0)
	{
		_strcpy(owd, cwd);
		getcwd(cwd, CWDBUFF);
	}
	return (0);
}

/**
 * fun_exit - exits shell
 *
 * @argv: catches last argument
 *
 * Return: nothing
 */
int fun_exit(char **argv)
{
	if (argv)
		exit(EXIT_SUCCESS);
	exit(EXIT_SUCCESS);
}
