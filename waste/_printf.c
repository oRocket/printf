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
			count += handle_conversion_specifier(args, *format);
		}
		format++;
	}

	va_end(args);
	return (count);
}
