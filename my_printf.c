#include "main.h"
/**
 * _printf - print to std format
 * @format: format
 * Return: number of bytes to be printed
 */
int _printf(const char *format, ...)
{
	unsigned int a, count = 0, count_s;
	va_list argumts;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(argumts, format);

	for (a = 0; format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			_putc(format[a]);
		}
		else if (format[a + 1] == 'c')
		{
			_putc(va_arg(argumts, int));
			a += 1;
		}
		else if (format[a + 1] == 's')
		{
			count_s = _benedict(va_arg(argumts, const char *));
			a += 1;
			count += (count_s - 1);
		}
		else
		{
			_putc('%');
		}
		count++;
	}
	va_end(argumts);

	return (count);
}
