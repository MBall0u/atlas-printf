#ifndef main_h
#define main_h

/**
 * struct specifier - struct specifier
 * 
 * @spec: the format specifier
 * @f: the function associated
*/
typedef struct specifier
{
	char spec;
	void (*f)(va_list);
} spec_t;

int _printf(const char *format, ...);
int (*get_spec_func(char *s))(va_list args);
int _strcmp(char *s1, char *s2);
int print_character(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_decimal(va_list args);
int print_integer(va_list args);
#endif

