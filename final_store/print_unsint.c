#include "main.h"
/**
 * print_unsint - Prints unsigned integer
 * @args: Points to the list of arguments
 * @count: Pointer to counter
 * Return: Always 0 success
 */
int print_unsint(va_list args, int *count)
{
	unsigned int numb = va_arg(args, unsigned int);
	char buffer[32];
	int buffer_index, c = 0;

	buffer_index = 0;

	if (numb == 0)
	{
		_putc('0');
		c++;
	}
	else
	{
		/* Convert the number to its string representation */
		for (; numb > 0; numb /= 10)
		{
			buffer[buffer_index] = (numb % 10) + '0';
			buffer_index++;
		}

		buffer_index--;

		/* Print the string representation in reverse order */
		for (; buffer_index >= 0; buffer_index--)
		{
			_putc(buffer[buffer_index]);
			c++;
		}
	}
	(*count) = (*count) + c;
	return (0);
}

