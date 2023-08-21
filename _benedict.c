#include "main.h"
/**
 * _benedict - Prints a string to stdout followed by a newline
 * @c: The string to be printed
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _benedict(const char *c)
{
	int count = 0;

	while (*c)
	{
		_putc(*c);
		c++;
		count++;
	}

	return (count);
}
