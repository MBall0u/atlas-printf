#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * print_character - prints a character
 * Description - initializes a pointer to a character, then prints it out
 * Return: Always 0 (success)
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
 * Return: Always 0 (success)
*/
void print_string(va_list args)
{
	int c = 0;
	char *str = va_arg(args, char *);

	while (str[c] != '\0')
	{
		putchar(str[c]);
		c++;
	}
}
/**
 * print_percent - prints the % sign
 * Description - prints '%'
 * Return: Always 0 (success)
*/
void print_percent(va_list args __attribute__ ((unused)))
{
	putchar('%');	
}
/**
 * print_decimal - initializes a pointer to an array of ints and a decimal point, and prints them.
 * Description - prints a decimal number
 * Return: Void
*/

void print_decimal(va_list args)
{
	int n = 0;
	char *dec = va_arg(args, char *)
	
	while (dec[n] != '\0' && dec[n] != '.')
	{
		putchar(dec[i];)
		n++;
	
		if (dec[n] == '.')
		{
			putchar('.')
		}
	}	
}

/**
 * print_integer - 
 * Description - 
 * Return: Always 0 (success)
*/

void print_integer(va_list args)
{
	int i = 0;
	char *number = va_arg(va_list, char *)
	
	while (number[i] != '\0')
	{
		putchar(number[i]);
		i++;
	}
}
