#include <stdlib.h>
#include <stdio.h>
#include "main.h"
/**
 * print_character - 
 * Description - 
 * Return: Always 0 (success)
*/
void print_character(va_list args)
{

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
 * print_percent - 
 * Description - 
 * Return: Always 0 (success)
*/
void print_percent(va_list args)
{

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