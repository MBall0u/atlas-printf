#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct specifier
{
    char spec;
    void (*f)(va_list);
} spec_t;

int _strlen(char *s)
{
    int count = 0;

    while (*s != '\0')
    {
        s++;
        count++;
    }
    return (count);
}

int char_counter(va_list args)
{
    int res = 0;
    char *temp = va_arg(args, char *);
    res += _strlen(&temp);
    return (res);
}

void print_character(va_list copiedArgs)
{
    char character = va_arg(copiedArgs, int);

    putchar(character);    
}

void print_string(va_list copiedArgs)
{
    int c = 0;
    char *str = va_arg(copiedArgs, char *);

    while (str[c] != '\0')
    {
        putchar(str[c]);
        c++;
    }
}

void print_percent(va_list args __attribute__ ((unused)))
{
    putchar('%');    
}

void (*get_spec_func(char s))(va_list copiedArgs)
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
    char *temp_format = format;
    int per_count = 0, res = 0;

    va_list(args);
    va_list(copiedArgs);
    va_copy(copiedArgs, args);
    va_start(args, format);
    va_start(copiedArgs, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            per_count++;
            
            if (*format == 's' || *format == 'c' || *format == '%')
            {
              res += (char_counter(args));
            }
            
            void (*print_func)(va_list) = get_spec_func(*format);

            if (print_func != NULL)
            {
                print_func(copiedArgs);
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
    return (res);    
}

int main(void)
{
    int len;
    int len2;
    
    len = _printf("Str:[%s]\n", "String!");
    len2 = printf("Str:[%s]\n", "String!");
    printf("Len:[%d, %i]\n", len, len);
    printf("Len:[%d, %i]\n", len2, len2);
    len = _printf("Perc:[%%]\n");
    len2 = printf("Perc:[%%]\n");
    printf("Len:[%d, %i]\n", len, len);
    printf("Len:[%d, %i]\n", len2, len2);
    return (0);
}