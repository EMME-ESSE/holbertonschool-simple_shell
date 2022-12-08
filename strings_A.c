#include "main.h"
/**
 * _strcpy - Copies the contents of a string to another string
 *
 * @src: Characters will be copied FROM this string
 * @dest: Characters will be copied TO this string.
 *
 * Return: void
 */
char *_strcpy(char *dest, char *src)
{
	int i, c;
	char *a;

	c = i = 0;
	for (; src[i] != '\0'; i++)
		c++;
	for (i = 0; c > -1; c--)
	{
		dest[i] = src[i];
		i++;
	}
	a = dest;
	return (a);
}

/**
 * _strcat - concatenates two strings
 *
 * @dest: String to be expanded
 * @src: text to be pasted into previous string
 *
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int i, c;
	char *a;

	c = -1;
	for (i = 0; dest[i] != '\0'; i++)
		;
	while (src[++c])
	{
		dest[i] = src[c];
		i++;
	}
	a = dest;
	return (a);
}
