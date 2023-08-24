#include "main.h"
/**
 * print_hexad - Prints hexadecimal representation of an unsigned long int
 * @n: Number to be converted
 * @count: Pointer to counter
 * Return: 0
 */
int print_hexad(unsigned long int n, int *count)
{
	char hex_buffer[32];
	int hex_buffer_index, c = 0;

	hex_buffer_index = 0;

	if (n == 0)
	{
		_putc('0');
		c++;
	}
	else
	{
		/* Convert the number to its hexadecimal representation */
		for (; n > 0; n /= 16)
		{
			hex_buffer[hex_buffer_index] = (n % 16) + (n % 16 > 9 ? 'a' - 10 : '0');
			hex_buffer_index++;
		}

		hex_buffer_index--;

		/* Print the hexadecimal representation in reverse order */
		for (; hex_buffer_index >= 0; hex_buffer_index--)
		{
			_putc(hex_buffer[hex_buffer_index]);
			c++;
		}
	}

	(*count) = (*count) + c;
	return (0);
}
