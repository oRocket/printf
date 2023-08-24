#include "main.h"
/**
 * handle_octal - Handles octal conversion
 * @args: va_list argument
 * @count: Pointer to the character count
 * @length_modifier: Length modifier value
 * @flags: Flags for formatting
 */
void handle_octal(va_list args, int *count, int length_modifier, int flags)
{
	if (length_modifier == 1)
		print_short_oct(args, count, flags);
	else if (length_modifier == 2)
		print_long_oct(args, count, flags);
	else
		print_oct(args, count);
}
