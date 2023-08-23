#include "main.h"
/**
 * print_long_HEX - Prints hexadecimal representation of a long int
 * @args: Points to the list of arguments
 * @count: Pointer to counter
 * Return: 0
 */
int print_long_HEX(va_list args, int *count)
{
	long int num = va_arg(args, long int);
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
	while (num > 0)
	{
		buffer[buffer_index] = hex_digits[num % 16];
		num /= 16;
		buffer_index++;
	}

	buffer_index--;

	/* Print the uppercase hexadecimal representation in reverse order */
	while (buffer_index >= 0)
	{
		_putc(buffer[buffer_index]);
		buffer_index--;
		(*count)++;
		c++;
	}

	return (0);
}
