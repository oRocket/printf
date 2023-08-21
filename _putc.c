#include "main.h"

/**
 * _putc - print a character
 * @c: character to be inputed
 * Return: 1
 */
int _putc(char c)
{
	return (write(1, &c, 1));
}
