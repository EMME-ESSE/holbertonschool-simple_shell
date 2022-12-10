#include "main.h"
/**
 * main - The entry point and main handler
 *
 * @ac: Argument count
 * @argv: argument variables
 *
 * return: 0 on success, -1 on failure.
 */
int main(int ac, char **argv)
{
	char *prompt = "(Hshell) $ ";
	char *line1 = NULL, *line2 = NULL;
	size_t n = 0;
	ssize_t chars_n = 0;
	const char *delim = " \"\t:,;\n";
	int num_tokens = 0;
	char *token = NULL;
	int i, check, bol_free_env = 0;
	(void)ac;

	/* Create a loop for the shell's prompt */
	while (1)
	{
		printf("%s", prompt);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		chars_n = getline(&line1, &n, stdin);
	        /* check if the getline function failed or user use CTRL + D */
		if (chars_n == -1)
		{
			printf("Exiting Hshell...\n");
			chars_n = 4;
			n = 4;
			free(line1);
			line1 = _strcut("F", "Fexit");
		}
		/* allocate space for a copy of the input */
		line2 = malloc(sizeof(char) * chars_n + 1);
		if (!line2)
		{
			perror("Memory allocation error");
			free(line1);
			return (-1);
		}
		_strcpy(line2, line1);
		/* splits the array and calculates the total number of tokens */
		token = strtok(line1, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens + 1);
		if (!argv)
		{
			perror("Memory allocation error");
			free(line1);
			free(line2);
			return(-1);
		}
		/* Store each token in argv */
		token = strtok(line2, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * _strlen(token) + 1);
			if (argv[i] == NULL)
			{
				perror("Memory allocation error");
				return(-1);
			}
			_strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
        	check = __launch(argv);
		for (; i >= 0; i--)
			free(argv[i]);
		free(argv);
		free(line2);
		if (check == 3)
			bol_free_env = 1;
		if (check == 4 || check == 5)
		{
			if (bol_free_env == 1)
				_setenv("OLDPWD=", "dummy", 0);
			free(line1);
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
