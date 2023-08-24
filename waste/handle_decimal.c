#include "main.h"
/**
 * handle_decimal - Handle decimal conversion specifier
 * @args: The va_list of arguments
 * @count: Pointer to the character count
 * @length_modifier: Length modifier value
 * @flags: Flags for formatting
 */
void handle_decimal(va_list args, int *count, int length_modifier, int flags)
{
	if (length_modifier == 1)
		print_short_decimal(args, count, flags);
	else if (length_modifier == 2)
		print_long_decimal(args, count, flags);
	else
		print_decimal(args, count);
}
