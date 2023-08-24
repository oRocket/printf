#include "main.h"
/**
 * print_char - Prints a character
 * @args: arguments
 * @count: Pointer to counter
 * Return: Always (0) Success
 */
int print_char(va_list args, int *count)
{
	char c = va_arg(args, int);

	_putc(c);
	(*count)++;
	return (0);
}
