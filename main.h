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

#endif

