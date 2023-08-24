#include "main.h"
/**
 * handle_format - Handles the format string and
 * calls appropriate conversion functions
 * @format: The format string
 * @args: The va_list containing arguments
 * Return: Number of characters printed
 */
int handle_format(const char *format, va_list args)
{
	int count = 0;
	int flags = 0;
	int length_modifier = 0; /* 0: None, 1: 'h', 2: 'l' */

	while (*format != '\0')
	{
		if (*format != '%')
		{
			_putc(*format);
			count++;
		}
		else
		{
			format++;
			/* Handle length modifiers */

			if (*format == 'h')
			{
				length_modifier = 1;
				format++;
			}
			else if (*format == 'l')
			{
				length_modifier = 2;
				format++;
			}

			switch (*format)
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
					handle_decimal(args, &count, flags, length_modifier);
					break;
				case 'u':
					handle_unsint(args, &count, flags, length_modifier);
					break;
				case 'o':
					handle_oct(args, &count, flags, length_modifier);
					break;
				case 'x':
					handle_hex(args, &count, flags, length_modifier);
					break;
				case 'X':
					handle_HEX(args, &count, flags, length_modifier);
					break;
				default:
					_putc('%');
					_putc(*format);
					count += 2;
			}
		}
		format++;
	}

	return (count);
}
