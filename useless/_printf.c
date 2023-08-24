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
	count = handle_format(format, args);
	va_end(args);

	return (count);
}

