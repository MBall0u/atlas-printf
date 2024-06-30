#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <stdarg.h>
/**
 *
 *
 *
 *
*/
int char_counter(const char *str)
{
	int res = 0;

	res += _strlen(str);
	return (res);
}
/**
 *
 *
 *
*/
int single_count(char c __attribute__ ((unused)))
{
	return (1);
}
