#include <stdio.h>
/**
 * print_binary - prints a decimal as binary
 * Description - Takes in a decimal and then uses
 * bitwise functions to print out the decimal in binary
 * @n: the inputted decimal
 * Return: void
*/
void print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int = 1;

	while (i < n)
	{
		i <<= 1;
		if (i > n)
		{
			i >>= 1;
			break;
		}
		if (i == n)
			break;
	}
	while (i > 0)
	{
		if (n >= 1)
		{
			_putchar('1');
			n -= 1;
		}
		else
			_putchar('0');
		i >>= 1;
	}
}