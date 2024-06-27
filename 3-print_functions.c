#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * print_character - prints a character
 * Description - initializes a pointer to a character, then prints it out
 * Return: Always 0 (success)
*/
int print_character(va_list args)
{
	char *character = va_arg(args, char *);

	putchar((char)character);	

	return(0);
}
/**
 * print_string - prints a string of characters
 * Description - initializes a pointer to the passed argument
 * and prints it out
 * Return: Always 0 (success)
*/
int print_string(va_list args)
{
	int c = 0;
	char *str = va_arg(args, char *);

	while (str[c] != '\0')
	{
		putchar(str[c]);
		c++;
	}
	return (0);
}
/**
 * print_percent - prints the % sign
 * Description - prints '%'
 * Return: Always 0 (success)
*/
int print_percent(va_list args)
{
	char *character = va_arg(args, char *);

	putchar((char)character);	

	return(0);
}
/**
 * print_decimal - 
 * Description - 
 * Return: Always 0 (success)
*/
/**
 * void print_decimal(va_list args)
{

}
*/
/**
 * print_integer - 
 * Description - 
 * Return: Always 0 (success)
*/
/**
void print_integer(va_list args)
{

}
*/