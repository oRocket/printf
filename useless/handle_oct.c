#include "main.h"

/**
 * handle_decimal - Handles the 'd' and 'i' conversion specifiers
 * with flags and length modifiers
 * @args: The va_list containing arguments
 * @count: Pointer to the counter for characters printed
 * @flags: Flags for formatting ('+', ' ', '#')
 * @length_modifier: Length modifier ('h', 'l')
 */
void handle_decimal(va_list args, int *count, int flags, int length_modifier)
{
	if (length_modifier == 1)
		print_short_decimal(args, count, flags);
	else if (length_modifier == 2)
		print_long_decimal(args, count, flags);
	else
		print_decimal(args, count, flags);
}

