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
			fprintf(stderr, "bash: %s: ", *argv);
			perror("");
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
			fprintf(stderr, "bash: %s: %s: ", *argv,  argv[1]);
			perror("");
			free(owd);
			return (-1);
		}
		free(owd);
		return(3);
	}
	else
	{
		if (chdir(argv[1]) != 0)
		{
			fprintf(stderr, "bash: %s: %s: ", *argv,  argv[1]);
			perror("");
			return (-1);
		}
	}
	free(owd);
	return (0);
}

/**
 * fun_exit - exits shell
 *
 * @argv: catches last argument
 *
 * Return: 4 to exit success
 */
int fun_exit(char **argv)
{
	if (argv)
		return (4);
	return (4);
}

/**
 * fun_env - prints the env vars
 *
 * @argv: catches last argument
 *
 * Return: 0 success
 */
int fun_env(char **argv)
{
	char **env = environ;

	while (*env) {
		printf("%s\n", *env);
		env++;
	}
	if (argv)
		return (0);
	return (0);
}
