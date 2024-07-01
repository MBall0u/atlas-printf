## Atlas-printf

# Synopsis

This is a simple version of the printf function found in the standard library of the C programming language. 
Available Conversion specifiers:
%c: Prints a single character
%s: Prints a string of characters 
%d: Prints integers 
%i: Prints integers.
%%: Prints Literal ‘%’

# Description
This version of printf uses variadic functions, structs, and multiple helper functions to print inputed characters, strings, percent signs, integers, and decimals. When executed successfully, it will also return the number of characters printed. If it fails, it will return a "-1" and "(null)".