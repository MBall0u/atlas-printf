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

	if (a == 0)
		return (1);
	if (a < 0)
	{
		a *= -1;
		count++;
	}
	if (a > 0)
	{
		while (a > 0)
		{
      	a /= 10;
      	count++;
    	}
	}
	return (count);
}
/**
 * positive_num - uses an integer input from the d and i case
 * to print the number off
 * Description - see above
 * @a: the derived variable
 * Return: Always 0 (success)
*/
void positive_num(int a)
{
	char tarray[50];
    int n = 0, temp = a, count = 0;

	while (temp > 0)
	{
		temp /= 10;
		count++;
	}
	for (n = count - 1; n >= 0; n--)
	{
		temp = a % 10;
		tarray[n] = (temp + '0');
		a /= 10;
	}
	n++;
	while (n < count)
	{
		putchar(tarray[n]);
		n++;
	}
}