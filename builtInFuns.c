#include "main.h"
int fun_cd(char**);
int fun_env(char**);
int fun_exit(char**);

char *builtin_str[] = {
  "cd",
  "exit"
};
int (*builtin_func[]) (char **) = {
  &fun_cd,
  &fun_exit
};
int _builtin_n() {
  return sizeof(builtin_str) / sizeof(char *);
}

/**
 * fun_cd - executes the chdir function with a given parameter
 *
 * @argv: argument for chdir
 * return: 0 on success, -1 on error.
 */
int fun_cd(char **args)
{
  if (args[1] == NULL)
  {
    fprintf(stderr, "44 Error: expected argument to \"cd\"\n");
    return (-1);
  }
  else
  {
    if (chdir(args[1]) != 0)
    {
      perror("45 Error");
      return (-1);
    }
  }
  return (0);
}

/**
 * fun exit - exits shell
 * return: always 0 */
int fun_exit(void)
{
	return (0);
}
