#include "main.h"
/**
 * fun_cd - executes the chdir function with a given parameter
 *
 * @argv: argument for chdir
 *
 * Return: 3 on success, -1 on error.
 */
int fun_cd(char **argv)
{
	char *env = NULL, cwd[CWDBUFF], *owd = NULL;

	getcwd(cwd, CWDBUFF);
	owd = _strcut("OLDPWD=", _getenv("OLDPWD"));

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
		_setenv("OLDPWD=", cwd, 1);
		if (chdir(owd) != 0)
		{
			perror("Error");
			free(owd);
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
	free(owd);
	return (3);
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
		return (4);
	return (4);
}
