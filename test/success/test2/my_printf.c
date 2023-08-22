#include "main.h"
/**
 * _printf - a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char *format, ...)
{
	va_list argmt;
	int a = 0, b, len = 0;
	sp_char type[] = {
		{"%s", printf_str}, {"%c", printf_char},
		{"%%", printf_percent}};

	va_start(argmt, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (a = 0; format[a] != '\0';)
	{
		for (b = 0; b < 14; b++)
		{
			if (type[b].fs[0] == format[a] && type[b].fs[1] == format[a + 1])
			{
				len += type[b].fs(argmt);
				a += 2;
				goto LoopExit;
			}
		}
		_putc(format[a]);
		len++;
		a++;
	}
LoopExit:
	va_end(argmt);
	return (len);
}
