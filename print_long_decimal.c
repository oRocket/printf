#include "main.h"
/**
 * print_long_decimal - Prints decimal representation of a long int
 * @args: Points to the list of arguments
 * @count: Pointer to counter
 * @flags: Flags indicating formatting options (+, space, #)
 * Return: Always (0) success
 */
int print_long_decimal(va_list args, int *count, int flags)
{
	long int num = va_arg(args, long int);
	int digits = 0;
	int temp, c = 0;

	if (num < 0)
	{
		_putc('-');
		(*count)++;
		num = -num;
	}
	else if (flags & FLAG_PLUS)
	{
		_putc('+');
		(*count)++;
	}
	else if (flags & FLAG_SPACE)
	{
		_putc(' ');
		(*count)++;
	}
	temp = num;
	do

	{
		temp /= 10;
		digits++;
	}

	while (temp > 0);

	while (digits > 0)
	{
		_putc('0' + (num / power(10, digits - 1)) % 10);
		(*count)++;
		digits--;
		c++;
	}
	return (0);
}
