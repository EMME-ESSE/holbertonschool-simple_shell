#include "main.h"
/*Main shell program*/
iint main(int ac, char **argv)
{
	char *prompt = "(hshell) $ ";
	char *line1 = NULL, *line2 = NULL;
	size_t n = 0;
	ssize_t nchars_read; /*chars_rd*/
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;
	(void)ac;

    /* Create a loop for the shell's prompt */
	while (1)
	{
		printf("%s", prompt);
		chars_rd = getline(&line1, &n, stdin);
	        /*function failed or user CTRL + D */ 
		if (chars_rd == -1)
		{
			printf("Exiting shell...\n");
			return (-1);
		}
       	 /* allocate space for a copy of the line1 */
		line2 = malloc(sizeof(char) * chars_rd);
		if (line2== NULL)
		{
			perror("memory allocation error");
			return (-1);
		}
        /* copy line1 to line2 */
		strcpy(line2, line1);
        /*split the string*/
        /* counter for tokens */
		token = strtok(line1, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
        /* Allocate space to hold the array of strings */
		argv = malloc(sizeof(char *) * num_tokens);
        /* Store each token */
		token = strtok(line2, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
        /* execute the command */
		execmd(argv);
	}
    /* free up allocated memory */
	free(line2);
	free(line1);
	return (0);
}
