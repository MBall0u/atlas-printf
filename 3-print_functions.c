#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * print_character - prints a character
 * Description - initializes a pointer to a character, then prints it out
 * Return: Void
*/
void print_character(va_list args)
{
	char character = va_arg(args, int);

	putchar(character);
}
/**
 * print_string - prints a string of characters
 * Description - initializes a pointer to the passed argument
 * and prints it out
 * Return: Void
*/
void print_string(va_list args)
{
	int c = 0;
	const char *str = va_arg(args, const char *);

	if (str == NULL)
	{
		putchar('(');
		putchar('n');
		putchar('u');
		putchar('l');
		putchar('l');
		putchar(')');
	}
	else
	{
		while (str[c] != '\0')
		{
			putchar(str[c]);
			c++;
		}
	}
}
/**
 * print_percent - prints the % sign
 * Description - prints '%'
 * Return: Void
*/
void print_percent(va_list args __attribute__ ((unused)))
{
	putchar('%');
}
/**
 * print_decimal - initializes a pointer to an array of ints and a decimal point
 * Description - prints a decimal number
 * Return: Void
*/
void print_decimal(va_list args)
{
	int n = 0;
	char *dec = va_arg(args, char *);

	while (dec[n] != '\0' && dec[n] != '.')
	{
		putchar(dec[n]);
		n++;
	
		if (dec[n] == '.')
		{
			putchar('.');
		}
	}
}
/**
 * print_integer - initializes pointer to array of ints 
 * Description - prints an integer
 * Return: Void
*/
void print_integer(va_list args)
{
	int i = 0;
	char *number = va_arg(args, char *);

	while (number[i] != '\0')
	{
		putchar(number[i]);
		i++;
	}
}
