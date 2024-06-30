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
int char_counter(va_list copiedArgs)
{
	res = 0;
	char *temp;
		
	temp = va_arg(copiedArgs, char *);
	res += _strlen(temp);
	c++
}