#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct specifier
{
    char spec;
    void (*f)(const char *str);
} spec_t;

int _strlen(const char *s)
{
    int count = 0;

    while (*s != '\0')
    {
        count++;
        s++;
    }
    return (count);
}

int char_counter(const char *str)
{
    int res = 0;
    const char *temp = str;
    res += _strlen(temp);
    return (res);
}

void print_character(char c)
{
    putchar(c);    
}

void print_string(const char *str)
{
    int c = 0;

    while (str[c] != '\0')
    {
        putchar(str[c]);
        c++;
    }
}

void print_percent(char c __attribute__ ((unused)))
{
    putchar('%');    
}

void (*get_spec_func(char s))(const char *str)
{
    spec_t specs[] = {
        {'c', print_character},
        {'s', print_string},
        {'%', print_percent},
    };
    int i = 0;

    while (i < 3)
    {
        if (specs[i].spec == s)
        {
            return (specs[i].f);
        }
        i++;
    }
    return (NULL);
}

int _printf(const char *format, ...)
{
    char *temp_arg;
    char temp_char;
    const char *temp_format = format;
    int per_count = 0, res = 0;

    va_list(args);
    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            per_count++;
            
            if (*format == 's')
            {
                temp_arg = va_arg(args, char *);
                res += (char_counter(temp_arg));
                void (*print_func)(const char *str) = get_spec_func(*format);
                if (print_func != NULL)
                {
                    print_func(temp_arg);
                }
                else
                {
                    return (1);
                }
            }
            if (*format == '%' || *format == 'c')
            {
                temp_char = va_arg(args, char);
                void (*print_func)(char c) = get_spec_func(*format);
                res += 1;
                if (print_func != NULL)
                {
                    print_func(temp_char);
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
    res += (_strlen(temp_format) - (per_count * 2));
    va_end(args);
    return (res);    
}

int main(void)
{
    int len;
    int len2;
    
    len = _printf("Char:[%c]\n", 'H');
    len2 = printf("Char:[%c]\n", 'H');
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    return (0);
}