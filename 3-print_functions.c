#include <stdlib.h>
#include <stdio.h>
#include "main.h"
/**
 * print_character - prints a character
 * Description - initializes a pointer to a character, then prints it out
 * Return: Always 0 (success)
*/
void print_character(va_list args)
{
	char *character = va_arg(args, char *);

	putchar(character);	
}
/**
 * print_string - prints a string of characters
 * Description - initializes a pointer to the passed argument
 * and prints it out
 * Return: Always 0 (success)
*/
void print_string(va_list args)
{
	int c = 0;
	char *str = va_arg(args, char *);

	while (str[c] != '\0')
	{
		putchar(str[c]);
		c++;
	}
}
/**
 * print_percent - prints the % sign
 * Description - initializes a pointer to the % sign and prints it out
 * Return: Always 0 (success)
*/
void print_percent(va_list args)
{
	putchar ('%');
}
/**
 * print_decimal - 
 * Description - 
 * Return: Always 0 (success)
*/
void print_decimal(va_list args)
{

}
/**
 * print_integer - 
 * Description - 
 * Return: Always 0 (success)
*/
void print_integer(va_list args)
{

}