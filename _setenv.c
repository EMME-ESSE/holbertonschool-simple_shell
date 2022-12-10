#include "main.h"
/**
 * _setenv - attempts to set an env variable
 *
 * @envy: variable to set, I.E. "PWD="
 * @newvalue: New value to store
 * @op: whether to allocate or free the pointer
 *
 * Return: 0 on success, -1 on failure.
 * Description: Warning, this is dangerous, just use the normal set env
 * I just created this function in order to change $OLDPWD
 */
int _setenv(char *envy, char *newValue, int op)
{
	int i, envSize, valSize, index = -1;
	char *new_value = NULL;

	for (envSize = 0; envy[envSize] != '\0'; envSize++)
		;
	for (valSize = 0; newValue[valSize] != '\0'; valSize++)
		;
	for (i = 0; environ[i] != NULL; i++)
		if (strncmp(environ[i], envy, envSize) == 0)
		{
			index = i;
			break;
		}
	if (index == -1)
		return(-1);
	if (op == 1)
	{	/** Modify the value of the environment variable */
		envSize = (envSize + valSize) * sizeof(char);
		if (!new_value)
			new_value = malloc(envSize);
		else
			new_value = realloc(new_value, envSize);
		if (!new_value)
		{
			fprintf(stderr, "Failed to allocate memory to heap");
			return (-1);
		}
		_strcpy(new_value, envy);
		_strcat(new_value, newValue);
		environ[index] = new_value;
	}
	else
	{	/** If op = 0, free the value */
		new_value = environ[index];
		if (new_value)
			free(new_value);
	}
	return (0);
}
