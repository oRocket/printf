#include "main.h"
/**
 * print_decimal - Prints decimal of an integer
 * @args: arguments
 * @count: Pointer to counter
 * Return: Always (0) Success
 */
int print_decimal(va_list args, int *count)
{
	int num = va_arg(args, int);
	int digits = 0;
	int temp;

	if (num < 0)
	{
		_putc('-');
		(*count)++;
		num = -num;
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
	}

	return (0);
}
