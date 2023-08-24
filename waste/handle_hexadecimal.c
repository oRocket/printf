#include "main.h"
/**
 * handle_hexadecimal - Handles hexadecimal conversion
 * @args: va_list argument
 * @count: Pointer to the character count
 * @length_modifier: Length modifier value
 * @flags: Flags for formatting
 * @uppercase: Flag for uppercase formatting
 */
void handle_hexadecimal(va_list args, int *count, int length_modifier,
		int flags, int uppercase)
{
	if (length_modifier == 1)
		print_short_hex(args, count, flags, uppercase);
	else if (length_modifier == 2)
		print_long_hex(args, count, flags, uppercase);
	else
		print_hex(args, count, flags, uppercase);
}

