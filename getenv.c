#include "main.h"
/**
 * read_textfile - reads a file and returns it
 *
 * @filename: Name of the file to read
 * @letters: Amount of characters it managed to read
 *
 * Return: 1 on success, 0 on failure
 */
char *_getenv(void)
{
	const char *filename = "/etc/environment";
	char *bufz;
	int filz;

	bufz = malloc(PATBUFF * sizeof(char));
	for (; filz < PATBUFF; filz++)
		bufz[filz] = '\0';

	filz = open(filename, O_RDONLY);

	if (filz != -1)
		read(filz, bufz, PATBUFF);
	else
		perror("Error:");
	close(filz);
	return (bufz);
}
