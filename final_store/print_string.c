#include "main.h"
/**
 * print_string - Prints a string
 * @args: Points to the list of arguments
 * @count: Pointer to counter
 * Return: Always 0 success
 */
int print_string(va_list args, int *count)
{
	char *str = va_arg(args, char *);

	while (*str != '\0')
	{
		_putc(*str);
		str++;
		(*count)++;
	}
	return (0);
}
