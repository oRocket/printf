#include "main.h"
static char hex_digits[] = "0123456789abcdef";
/**
 * print_long_hex - Prints long int in lowercase hexadecimal representation
 * @args: Points to the list of arguments
 * @count: Pointer to counter
 * @flags: Flags indicating formatting options (#)
 * Return: 0
 */
int print_long_hex(va_list args, int *count, int flags)
{
	unsigned long int num = va_arg(args, unsigned long int);
	char buffer[32];
	int buffer_index = 0;

	if (num == 0)
	{
		if (flags & FLAG_HASH)
		{
			_putc('0');
			_putc('x');
			(*count) += 2;
		}
		_putc('0');
		(*count)++;
		return (1);
	}

	if (flags & FLAG_HASH)
	{
		_putc('0');
		_putc('x');
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
	}
	return (0);
}
