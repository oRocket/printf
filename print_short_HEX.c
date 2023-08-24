#include "main.h"
/**
 * print_short_HEX - Prints short int in uppercase hexadecimal representation
 * @args: Points to the list of arguments
 * @count: Pointer to counter
 * @flags: Flags indicating formatting options (#)
 * Return: Always (0) success
 */
int print_short_HEX(va_list args, int *count, int flags)
{
	short int num = (short int)va_arg(args, int);
	char buffer[32], hex_digits[] = "0123456789ABCDEF";
	int buffer_index = 0, c = 0;

	if (num == 0)
	{
		if (flags & FLAG_HASH)
		{
			_putc('0');
			_putc('X');
			(*count) += 2;
		}
		_putc('0');
		(*count)++;
		return (1);
	}

	if (flags & FLAG_HASH)
	{
		_putc('0');
		_putc('X');
		(*count) += 2;
	}

	while (num > 0)
	{
		buffer[buffer_index] = hex_digits[num % 16];
		num /= 16;
		buffer_index++;
	}
	buffer_index--;

	while (buffer_index >= 0)
	{
		_putc(buffer[buffer_index]);
		buffer_index--;
		(*count)++;
		c++;
	}
	return (0);
}
