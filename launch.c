#include "main.h"
/**
 * __launch - attempts to run a builtin, if it fails runs a command
 *
 * @argv: argument and flags
 *
 * Return: Builtin fun || command fun
 */
int __launch(char **argv)
{
	int i, funCnt;

	char *builtin_str[] = {
		"cd",
		"exit"
	};

	int (*builtin_func[])(char **) = {
		&fun_cd,
		&fun_exit
	};

	/** this just a counter, counts the n of builtins*/
	funCnt = (sizeof(builtin_str) / sizeof(char *));

	if (argv[0] == NULL)
	{ /** this handles empty arguments */
		return (1);
	}

	for (i = 0; i < funCnt; i++)
	{/** compares argument to fun names */
		if (strcmp(argv[0], builtin_str[i]) == 0)
		{/** executes the fun */
			return ((*builtin_func[i])(argv));
		}
	}
	return (execmd(argv));
}
