#include "main.h"
/**
 * handle_HEX - Handle uppercase hexadecimal conversion specifier
 * @args: The va_list containing the arguments
 * @count: Pointer to the count of printed characters
 * @flags: Flags for formatting
 * @length_modifier: Length modifier (0: None, 1: 'h', 2: 'l')
 */
void handle_HEX(va_list args, int *count, int flags, int length_modifier)
{
	unsigned int num;
	char buffer[32];
        int buffer_index = 0;

	if (length_modifier == 1)
		num = va_arg(args, unsigned int);
	else if (length_modifier == 2)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);

	while (num > 0)
	{
		buffer[buffer_index] = (num % 16) + (num % 16 > 9 ? 'A' - 10 : '0');
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
}
