#include "main.h"
/**
 * print_short_hex - Prints lowercase hexadecimal representation of a short int
 * @args: Points to the list of arguments
 * @count: Pointer to counter
 * Return: Always (0) success
 */
int print_short_hex(va_list args, int *count)
{
	short int num = (short int)va_arg(args, int); /* Cast to short int */
	char buffer[32];
	int buffer_index = 0;
	int c = 0;
	char hex_digits[] = "0123456789abcdef";

	if (num == 0)
	{
		_putc('0');
		(*count)++;
		return (1);
	}

	/* Convert the number to lowercase hexadecimal representation */
	while (num > 0)
	{
		buffer[buffer_index] = hex_digits[num % 16];
		num /= 16;
		buffer_index++;
	}

	buffer_index--;

	/* Print the lowercase hexadecimal representation in reverse order */
	while (buffer_index >= 0)
	{
		_putc(buffer[buffer_index]);
		buffer_index--;
		(*count)++;
		c++;
	}

	return (0);
}
