#include "main.h"
/**
 * print_long_oct - Prints octal representation of a long int
 * @args: Points to the list of arguments
 * @count: Pointer to counter
 * Return: Always (0) Success
 */
int print_long_oct(va_list args, int *count)
{
	long int num = va_arg(args, long int);
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
