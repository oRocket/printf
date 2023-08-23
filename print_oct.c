#include "main.h"
/**
 * print_oct - Prints octal representation of an unsigned int
 * @args: va_list pointing to the arguments
 * @count: Pointer to counter
 * Return: Number of characters printed
 */
int print_oct(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[32];
	int buffer_index = 0;

	if (num == 0)
	{
		_putc('0');
		(*count) = (*count) + 1;
		return (1);
	}

	for (; num > 0; num /= 8)
	{
		buffer[buffer_index] = (num % 8) + '0';
		buffer_index++;
	}

	buffer_index--;

	for (; buffer_index >= 0; buffer_index--)
	{
		_putc(buffer[buffer_index]);
		(*count)++;
	}
	return (0);
}
