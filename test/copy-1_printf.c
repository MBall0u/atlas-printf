#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - This is a homebrew version of standard libraries printf
 * Description - This function takes a formatted string as input as well as
 * an unknown amount of variables. It starts iterating through the string until
 * it hits a format specifier which then passes the next character into a function
 * that finds the proper formatting to print the inputted argument thus replacing
 * the format specifier in the string and then continues iterating until it hits
 * another format specifier or a null byte infinitely
 * @format: a formatted sting to be printed to standard output
 * Return: Always 0 (success)
*/
int _printf(const char *format, ...)
{
	void (*print_func)(va_list);

	va_list(args);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				putchar(*format);
			}
			else
			{
				print_func = get_spec_func(*format);

				if (print_func != NULL)
				{
					print_func(args);
				}
				else
				{
					return (1);
				}
			}
		}
		else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (0);
}