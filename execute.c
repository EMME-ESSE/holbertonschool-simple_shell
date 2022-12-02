#include "main.h"

int fun_execute(char **argv)
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

	funCnt = (sizeof(builtin_str) / sizeof(char *));

	if (argv[0] == NULL)
	{ /** this handles empty arguments */
		return (1);
	}

	for (i = 0; i < funCnt; i++)
	{
		if (strcmp(argv[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(argv));
		}
	}
	return (execmd(argv));
}
