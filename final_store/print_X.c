#include "main.h"
/**
 * print_HEX - Prints hexadecimal numbers in uppercase
 * @args: arguments
 * @count: Pointer to counter
 * Return: Count of characters to be printed
 */
int print_HEX(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[32];
	int buffer_index = 0;
	int c = 0;
	char hex_digits[] = "0123456789ABCDEF";

	if (num == 0)
	{
		_putc('0');
		(*count)++;
		return (1);
	}
	/* Convert the number to uppercase hexadecimal representation */
	do

	{
		buffer[buffer_index] = hex_digits[num % 16];
		num /= 16;
		buffer_index++;
	}

	while (num > 0);

	buffer_index--;
	/* Print the uppercase hexadecimal representation in reverse order */
	do

	{
		_putc(buffer[buffer_index]);
		buffer_index--;
		(*count)++;
		c++;
	}

	while (buffer_index >= 0);

	return (0);
}

