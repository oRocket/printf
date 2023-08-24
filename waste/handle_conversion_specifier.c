#include "main.h"
/**
 * handle_conversion_specifier - Handle the conversion specifier
 * @args: The va_list of arguments
 * @specifier: The conversion specifier
 * Return: Number of characters printed
 */
int handle_conversion_specifier(va_list args, char specifier)
{
	int count = 0;
	int flags = 0;
	int length_modifier = 0; /* 0: None, 1: 'h', 2: 'l' */

	/* Handle length modifiers */
	if (specifier == 'h')
	{
		length_modifier = 1;
		specifier = *(format + 1);
	}
	else if (specifier == 'l')
	{
		length_modifier = 2;
		specifier = *(format + 1);
	}

	switch (specifier)
	{
		case 'c':
			print_char(args, &count);
			break;
		case 's':
			print_string(args, &count);
			break;
		case '%':
			_putc('%');
			count++;
			break;
		case 'd':
		case 'i':
			handle_decimal(args, &count, length_modifier, flags);
			break;
		case 'u':
			handle_unsigned(args, &count, length_modifier, flags);
			break;
		case 'o':
			handle_octal(args, &count, length_modifier, flags);
			break;
		case 'x':
			handle_hexadecimal(args, &count, length_modifier, flags, 0);
			break;
		case 'X':
			handle_hexadecimal(args, &count, length_modifier, flags, 1);
			break;
		default:
			_putc('%');
			_putc(specifier);
			count += 2;
	}
	return (count);
}
