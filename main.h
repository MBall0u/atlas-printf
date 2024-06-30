#include <stdarg.h>

#ifndef MAIN_H
#define MAIN_H

/**
 * struct specifier - struct specifier
 * 
 * @spec: the format specifier
 * @f: the function associated
*/
typedef struct specifier
{
	char spec;
	void (*f)(va_list args);
} spec_t;

int _printf(const char *format, ...);
void (*get_spec_func(char s))(va_list args);
void print_character(va_list args);
void print_string(va_list args);
void print_percent(va_list args);
void print_decimal(va_list args);
void print_integer(va_list args);
int char_counter(const char *str);
int _strlen(const char *s);

#endif

