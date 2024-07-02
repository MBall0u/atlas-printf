#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * print_character - prints a character
 * Description - initializes a pointer to a character, then prints it out
 * @args: argument list being passed
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
 * @args: argument list being passed
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
 * @args: argument list being passed
 * Return: Void
*/
void print_percent(va_list args __attribute__ ((unused)))
{
	putchar('%');
}
/**
 * print_decimal - initializes a pointer to an array of ints & a '.'
 * Description - prints a decimal number
 * @args: argument list being passed
 * Return: Void
*/
void print_decimal(va_list args)
{
	int dec = va_arg(args, int);
	char tarray[50];
	int n = 0, temp = dec, count = 0;

	if (dec == 0)
		putchar(temp + '0');
	if (temp < 0)
	{
		temp *= -1;
		dec *= -1;
		count++;
		while (temp > 0)
		{
			temp /= 10;
			count++;
		}
		tarray[0] = '-';
		for (n = count - 1; n >= 1; n--)
		{
			temp = dec % 10;
			tarray[n] = (temp + '0');
			dec /= 10;
		}
		while (n < count)
		{
			putchar(tarray[n]);
			n++;
		}
	}
	else
	{
		positive_num(dec);
	}
}
/**
 * print_integer - initializes pointer to array of ints
 * Description - prints an integer
 * @args: argument list being passed
 * Return: Void
*/
void print_integer(va_list args)
{
	int dec = va_arg(args, int);
	char tarray[50];
	int n = 0, temp = dec, count = 0;

	if (dec == 0)
		putchar(temp + '0');
	if (temp < 0)
	{
		temp *= -1;
		dec *= -1;
		count++;
		while (temp > 0)
		{
			temp /= 10;
			count++;
		}
		tarray[0] = '-';
		for (n = count - 1; n >= 1; n--)
		{
			temp = dec % 10;
			tarray[n] = (temp + '0');
			dec /= 10;
		}
		while (n < count)
		{
			putchar(tarray[n]);
			n++;
		}
	}
	else
	{
		positive_num(dec);
	}
}
