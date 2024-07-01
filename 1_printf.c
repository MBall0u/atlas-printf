#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - This is a homebrew version of standard libraries printf
 * Description - This function takes a formatted string as input as well as
 * an unknown amount of variables. It starts iterating through the string until
 * it hits a format specifier which then passes thenext character intoafunction
 * that finds the proper formatting to print the inputted argument thus
 * replacing the format specifier in the string and then continues iterating
 * until it hits another format specifier/ null byte indefinetly.
 * @format: a formatted sting to be printed to standard output
 * Return: Always 0 (success)
*/
int _printf(const char *format, ...)
{
	int per_count = 0, res = 0, i = 0;

	va_list(args), (copiedargs);
	va_start(args, format);
	va_copy(copiedargs, args);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's' || format[i] == 'c' || format[i] == '%')
			{
				per_count++;
				res += char_func(format[i], copiedargs, args);
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				per_count++;
				res += digi_func(format[i], copiedargs, args);
			}
			else if (format[i] == '\0')
			{
				i--;
				continue;
			}
			else
			{
				i--;
				putchar(format[i]);
				i++;
				putchar(format[i]);
			}
		}
		else
			putchar(format[i]);
		i++;
	}
	res += (_strlen(format) - (per_count * 2));
	va_end(args);
	va_end(copiedargs);
	return (res);
}
/**
 * char_func - this is a character counting and printing function
 * Description - this function is called by _printf and is utilized
 * for any format specifier that is s, c, or %
 * @c: the inputted character from the formatted string
 * @copiedargs: the copied argument list being passed through
 * @args: the original argument list being passed
 * Return: the character counter res
*/
int char_func(const char c, va_list copiedargs, va_list args)
{
	const char *temp_arg;
	char temp_char;
	int res = 0;
	void (*print_func)(va_list args);

	if (c == 's')
	{
		temp_arg = va_arg(copiedargs, const char *);
		if (temp_arg == NULL)
		{
			temp_arg = "(null)";
		}
		res += (char_counter(temp_arg));
	}
	if (c == 'c')
	{
		temp_char = va_arg(copiedargs, int);
		res += single_count(temp_char);
	}
	if (c == '%')
	{
		res += 1;
	}

	print_func = get_spec_func(c);

	if (print_func != NULL)
	{
		print_func(args);
	}
	else
	{
		return (-1);
	}
	return (res);
}
/**
 * digi_func - the function counting
 * and printing the d and i cases
 * Description - see above
 * @c: the formatted string character being passed
 * through to find the correct print function
 * @copiedargs: the copied args list being passed to the counter
 * @args: the original args list being passed to the print functions
 * Return: res (success)
*/
int digi_func(const char c, va_list copiedargs, va_list args)
{
	int res = 0, temp_int;
	void (*print_func)(va_list args);

	temp_int = va_arg(copiedargs, int);
	res += digi_count(temp_int);

	print_func = get_spec_func(c);

	if (print_func != NULL)
	{
		print_func(args);
	}
	else
	{
		return (-1);
	}
	return (res);
}