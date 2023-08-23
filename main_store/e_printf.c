#include "main.h"
/**
 * _print - print to std format
 * @format: format
 * Return: number of bytes to be printed
 */
int _print(const char *format, ...)
{
	int count = 0, value;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
				case 'i':
					{
						value = va_arg(args, int);
						print_ints(1, value);
						break;
					}
				default:
					_putc('%');
					_putc(*format);
					break;
			}
		}
		else
		{
			_putc(*format);
		}
		format++;
		count++;
	}
	va_end(args);
	return (count);
}
