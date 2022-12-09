#include "main.h"
int main(int ac, char **argv)
{
	char *prompt = "(Hshell) $ ";
	char *line1 = NULL, *line2 = NULL;
	size_t n = 0;
	ssize_t chars_n;
	const char *delim = " \"\t:,;.\n";
	int num_tokens = 0;
	char *token;
	int i;
	(void)ac;

	while (1)
	{
		printf("%s", prompt);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		line1 = malloc(sizeof(char) * n);
		if (!line1)
		{
			free(line1);
			return(-1);
		}
		chars_n = getline(&line1, &n, stdin);
		if (chars_n == -1)
		{
			printf("Exiting Shell...\n");
			free(line1);
			return(-1);
     		}  
		line2 = malloc(sizeof(char *) * chars_n + 1);
		if (line2 == NULL)
		{
			perror("Memory allocation error");
			free(line2);
			return (-1);
		}
		strcpy(line2, line1);
		token = strtok(line1, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		if (!token)
		{
			free(line1);
			return(-1);
		}
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens + 1);
		if (argv == NULL)
		{
			perror("Memory allocation error");
			return(-1);
		}
		token = strtok(line2, delim);
		if (!token)
		{
			free(token);
			return(-1);
		}
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char *) * strlen(token) + 1);
			if (argv[i] == NULL)
			{
				perror("Memory allocation error");
				free(argv[i]);
				return(-1);
			}
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
       		__launch(argv);
		free(argv[i]);
		free(argv);
		free(line2);
		free(line1);
	}
	return (0);
}
