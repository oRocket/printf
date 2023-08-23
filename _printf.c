#include "main.h"
/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Additional arguments to format
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int length_modifier = 0; /* 0: None, 1: 'h', 2: 'l' */

	va_start(args, format);
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
					if (length_modifier == 1)
						print_short_decimal(args, &count);
					else if (length_modifier == 2)
						print_long_decimal(args, &count);
					else
						print_decimal(args, &count);
					break;
				case 'u':
					if (length_modifier == 1)
						print_short_unsint(args, &count);
					else if (length_modifier == 2)
						print_long_unsint(args, &count);
					else
						print_unsint(args, &count);
					break;
				case 'o':
					if (length_modifier == 1)
						print_short_oct(args, &count);
					else if (length_modifier == 2)
						print_long_oct(args, &count);
					else
						print_oct(args, &count);
					break;
				case 'x':
					if (length_modifier == 1)
						print_short_hex(args, &count);
					else if (length_modifier == 2)
						print_long_hex(args, &count);
					else
						print_hex(args, &count);
					break;
				case 'X':
					if (length_modifier == 1)
						print_short_HEX(args, &count);
					else if (length_modifier == 2)
						print_long_HEX(args, &count);
					else
						print_HEX(args, &count);
					break;
				default:
					_putc('%');
					_putc(*format);
					count += 2;
			}
		}
		format++;
	}

	va_end(args);
	return (count);
}
