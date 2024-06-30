#include "main.h"
/**
 * _strlen - returns the length of a string
 * @s: the string being counted
 * Return: the length of the string
*/
int _strlen(const char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}
