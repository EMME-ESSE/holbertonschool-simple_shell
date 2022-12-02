#include "main.h"

/**
 * fun_cd - executes the chdir function with a given parameter
 *
 * @argv: argument for chdir
 * return: 0 on success, -1 on error.
 */
int fun_cd(char **argv)
{
  if (argv[1] == NULL)
  {
    fprintf(stderr, "44 Error: expected argument to \"cd\"\n");
    return (-1);
  }
  else
  {
    if (chdir(argv[1]) != 0)
    {
      perror("45 Error");
      return (-1);
    }
  }
  return (0);
}

/**
 * fun exit - exits shell
 * return: always 0
 */
int fun_exit(char **argv)
{
	if (argv)
		exit(EXIT_SUCCESS);
	exit(EXIT_SUCCESS);
}
