#include "main.h"
/**
 * print_address - prints the address
 * @args: arguments
 * @count: Pointer to counter
 * Return: 1 if points to nothing, 0 otherwise
 */
int print_address(va_list args, int *count)
{
	void *address = va_arg(args, void *);
	char *nil_str = "(nil)";
	long int n;

	if (address == NULL)
	{
		_string(nil_str, _benedict(nil_str));
		(*count) = (*count) + _benedict(nil_str);
		return (1);
	}

	_putc('0');
	_putc('x');
	(*count) = (*count) + 2;
	n = (unsigned long int)address;

	do

	{
		char hex_digit = (n & 0xF);

		_putc(hex_digit < 10 ? hex_digit + '0' : hex_digit - 10 + 'a');
		(*count) = (*count) + 1;
		n >>= 4;
	}

	while (n > 0);

	return (0);
}
