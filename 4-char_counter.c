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
 * @c: unused variable
 * Return: Always 1 (success)
*/
int single_count(char c __attribute__ ((unused)))
{
	return (1);
}
/**
 * digi_count - counting how many characters
 * there are in an int
 * Description - see above
 * @a: the inputted int
 * Return: count (success)
*/
int digi_count(int a)
{
	int count = 0;

	if (a > 0)
	{
		while (a > 0)
		{
      	a /= 10;
      	count++;
    	}
	}
	if (a < 0)
	{
		a *= -1;
		count++;
		while (a > 0)
		{
			a /= 10;
			count++;
    	}
	}
	return (count);
}