#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

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
int single_count(char c);
int char_func(const char c, va_list copiedargs, va_list args);
int digi_func(const char c, va_list copiedargs, va_list args);
int digi_count(int a);
void positive_num(int a);

#endif

