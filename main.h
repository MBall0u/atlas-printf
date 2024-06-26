#ifndef main_h
#define main_h

struct specifier
{
	char *spec;
	void (*f)(va_list);
};

int _printf (const char *format, ...);
int (*get_spec_func(char *s))(va_list args);
int _strcmp(char *s1, char *s2);
void print_character(va_list args);
void print_string(va_list args);
void print_percent(va_list args);
void print_decimal(va_list args);
void print_integer(va_list args);
#endif

