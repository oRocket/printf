#include "main.h"
/**
 * print_short_oct - Prints octal representation of a short int
 * @args: Points to the list of arguments
 * @count: Pointer to counter
 * Return: Always (0) success
 */
int print_short_oct(va_list args, int *count)
{
	short int num = (short int)va_arg(args, int);
	char buffer[32];
	int buffer_index = 0;
	int c = 0;

	if (num == 0)
	{
		_putc('0');
		(*count)++;
		return (1);
	}

	/* Convert the number to octal representation */
	while (num > 0)
	{
		buffer[buffer_index] = (num % 8) + '0';
		num /= 8;
		buffer_index++;
	}

	buffer_index--;

	/* Print the octal representation in reverse order */
	while (buffer_index >= 0)
	{
		_putc(buffer[buffer_index]);
		buffer_index--;
		(*count)++;
		c++;
	}

	return (0);
}
