#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "(Hshell) $ ";
	char *line1 = NULL, *line2 = NULL;
	size_t n = 0;
	ssize_t chars_n;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;
	(void)ac;

    /* Create a loop for the shell's prompt */
	while (1)
	{
		printf("%s", prompt);
		chars_n = getline(&line1, &n, stdin);
	        /* check if the getline function failed or user use CTRL + D */ 
		if (chars_n == -1)
		{
			printf("Exiting Hshell...\n");
			return (-1);
		}
       	 /* allocate space for a copy of the input */
		line2 = malloc(sizeof(char) * chars_n);
		if (line2 == NULL)
		{
			perror("Memory allocation error");
			return (-1);
		}
		strcpy(line2, line1);
               /* splits the array and calculates the total number of tokens */
		token = strtok(line1, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens);
		if (argv == NULL)
		{
			perror("Memory allocation error");
			return(-1);
		}
        /* Store each token in argv */
		token = strtok(line2, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			if (argv[i] == NULL)
			{
				perror("Memory allocation error");
				return(-1);
			}
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
        	__launch(argv);
	}
	free(line2);
	free(line1);
	return (0);
}
