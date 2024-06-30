#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
/**
 * get_spec_func - pointer function to the format specifiers functions
 * Description - this function is a pointer function that takes
 * one argument and passes it to the matching format specifiers
 * function as stated in the struct
 * @s: this is the format specifier that is identified after the
 * percent sign and passed to this function
 * Return: Always 0 (success)
*/
void (*get_spec_func(char s))(va_list args)
{
	spec_t specs[] = {
		{'c', print_character},
		{'s', print_string},
		{'%', print_percent},
	};
	int i = 0;

	while (i < 2)
	{
		if (specs[i].spec == s)
		{
			return (specs[i].f);
		}
		i++;
	}
	return (NULL);
}