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
	const char *temp_arg;
    char temp_char;
    int per_count = 0, res = 0, i;
	void (*print_func)(va_list args);

	va_list(args);
	va_list(copiedargs);
	va_copy(copiedargs, args);
	va_start(args, format);
	va_start(copiedargs, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			per_count++;

			if (format[i] == 's')
			{
				temp_arg = va_arg(copiedargs, const char *);
				res += (char_counter(temp_arg));
			}
			if (format[i] == '%' || format[i] == 'c')
			{
				temp_char = va_arg(copiedargs, unsigned char);
				res += 1;
			}
			
			print_func = get_spec_func(format[i]);

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
			putchar(format[i]);
		}
		i++;
	}
	res += (_strlen(*format) - (per_count * 2));
	va_end(args);
	va_end(copiedargs);
	return (res);
}