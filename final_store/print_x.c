#include "main.h"
/**
 * print_hex - Prints lowercase hexadecimal
 * @args: arguments
 * @count: Pointer to counter
 * Return: Number of characters to be printed
 */
int print_hex(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[32];
	int buffer_index = 0;

	if (num == 0)
	{
		_putc('0');
		(*count)++;
		return (1);
	}
	/* Convert the number to lowercase hexadecimal representation */
	for (; num > 0; num /= 16)
	{
		buffer[buffer_index] = (num % 16) + (num % 16 > 9 ? 'a' - 10 : '0');
		buffer_index++;
	}
	buffer_index--;
	/* Print the lowercase hexadecimal representation in reverse order */
	for (; buffer_index >= 0; buffer_index--)
	{
		_putc(buffer[buffer_index]);
		(*count)++;
	}
	return (0);
}
