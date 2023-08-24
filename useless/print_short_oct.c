#include "main.h"
/**
 * print_short_oct - Prints short int in octal representation
 * @args: Points to the list of arguments
 * @count: Pointer to counter
 * @flags: Flags indicating formatting options (#)
 * Return: Always (0) success
 */
int print_short_oct(va_list args, int *count, int flags)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[32];
	int buffer_index = 0;

	if (num == 0)
	{
		if (flags & FLAG_HASH)
		{
			_putc('0');
			(*count)++;
		}
		return (1);
	}

	if (flags & FLAG_HASH)
	{
		_putc('0');
		(*count)++;
	}

	while (num > 0)
	{
		buffer[buffer_index] = (num % 8) + '0';
		num /= 8;
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
