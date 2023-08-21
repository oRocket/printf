#include "main.h"

/**
 * _putc - print a character
 * @c: character to be inputed
 * Return: 1
 */
int _putc(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
