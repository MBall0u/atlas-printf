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
	char *temp_arg;
    char temp_char;
    char *temp_format = format;
    int per_count = 0, res = 0;
	void (*print_func)(va_list args);

	va_list(args);
	va_list(copiedargs);
	va_copy(copiedargs, args);
	va_start(args, format);
	va_start(copiedargs, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			per_count++;

			if (*format == 's')
			{
				temp_arg = va_arg(copiedargs, char *);
				res += (char_counter(temp_arg));
			}
			if (*format == '%' || *format == 'c')
			{
				temp_char = va_arg(copiedargs, int);
				res += 1;
			}
			
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
		else
		{
			putchar(*format);
		}
		format++;
	}
	res += (_strlen(temp_format) - (per_count * 2));
	va_end(args);
	va_end(copiedargs);
	return (res);
}