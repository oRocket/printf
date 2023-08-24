#include "main.h"
/**
 * print_short_unsint - Prints unsigned short int in decimal representation
 * @args: Points to the list of arguments
 * @count: Pointer to counter
 * @flags: Flags indicating formatting options (#)
 * Return: 0
 */
int print_short_unsint(va_list args, int *count, int flags)
{
	short int num = (short int)va_arg(args, int);
	char buffer[32];
	int buffer_index = 0, c = 0;

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
		_putc('x');
		(*count) += 2;
	}

	while (num > 0)
	{
		buffer[buffer_index] = (num % 10) + '0';
		num /= 10;
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
