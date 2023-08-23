#include "main.h"                                          

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

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
			switch (*format)
			{
				case 'c':
					print_char(args, &count);                                                                                             break;
				case 's':
					print_string(args, &count);
					break;
				case '%':
					_putc('%');
					count++;
					break;
				case 'd':
				case 'i':
					print_decimal(args, &count);
					break;
				case 'u':
					print_unsint(args, &count);
					break;
				case 'p':
					print_address(args, &count);
					break;
				case 'o':
					print_oct(args, &count);
					break;
				case 'x':
					print_hex(args, &count);
					break;
				case 'X':
					print_HEX(args, &count);
					break;
				default:
					_putc('%');                                                _putc(*format);
					count += 2;
			}
		}
		format++;
	}

	va_end(args);
	return (count);
}
