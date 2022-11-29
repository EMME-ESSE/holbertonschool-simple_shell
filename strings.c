#include "main.h"
/**
 *_strlen - Count the number of characters
 *@string: String to count
 *Return: Number of characters
 */
int _strlen(char *string)
{
	int len = 0;

	while (string[len])
		len++;
	return (len);
}
/**
 *  * _strncpy - Copies at most an inputted number
 *   *            of bytes from string src into dest.
 *   * @dest: The buffer storing the string copy.
 *   * @src: The source string.
 *   * @n: The maximum number of bytes to copied from src.
 *   * Return: A pointer to the resulting dest.
**/
char *_strncpy(char *dest, char *src, int n)
{
	int index = 0, src_len = 0;
	
	while (src[index++])
		src_len++;
	for (index = 0; src[index] && index < n; index++)
		dest[index] = src[index];
	for (index = src_len; index < n; index++)
		dest[index] = '\0';
	return (dest);
}


/**
 * _strcmp - Compares pointers to two strings.
 * @s1: A pointer to the first string to be compared.
 * @s2: A pointer to the second string to be compared.
 * Return: If str1 < str2, the negative difference of
 * the unmatched characters.
 */
int _strcmp(char *s1, char *s2)
{
	int a = 0;

	while (s1[a] == s2[a])
	{
		if (s1[a] == '\0' || s2[a] == '\0')
			break;
		a++;
	}
	if (s1[a] == '\0' && s2[a] == '\0')
		return (0);
	else
		return (s1[a] - s2[a]);
}

/**
 *    _strncat - Concatenates two strings using at most
 *    an inputted number of bytes from src.
 *    * @dest: The string to be appended.
 *    * @src: The string to be appended to dest.
 *    * @n: The number of bytes from src to be appended to dest.
 *    * Return: A pointer to the resulting dest.
**/
char *_strncat(char *dest, char *src, int n)
{
	int index = 0, dest_len = 0;

	while (dest[index++])
		dest_len++;
	for (index = 0; src[index] && index < n; index++)
		dest[dest_len++] = src[index];
	return (dest);
}
