#include "main.h"
/**
 * _getenv - gets the desired environment
 *
 * @envy: name in mayus of the environment you want
 *
 * Return: Pointer to environment string, NULL on failure.
 */
char *_getenv(char *envy)
{
	int i = 0;

	while (environ[i++])
		if (_strcmp(environ[i], envy) == '=')
			break;
		else if (environ[i] == NULL)
		{
			fprintf(stderr, "bash: %s: ", envy);
			perror("");
		}

	return (environ[i]);
}
