#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <stdarg.h>
/**
 * char_counter - this counts the string arguments
 * passed to it.
 * Description - see above
 * @str: the string passed from the _printf function
 * Return: result counter
*/
int char_counter(const char *str)
{
	int res = 0;

	res += _strlen(str);
	return (res);
}
/**
 * single_count - gets passed a single character argument
 * Description - just returns a value of positive one for
 * character counter.
 * Return: Always 1 (success)
*/
int single_count(char c __attribute__ ((unused)))
{
	return (1);
}
