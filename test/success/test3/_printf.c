#include "main.h"

int _printf(const char *format, ...)
{
	int count = 0;
	const char *ptr = format;
	va_list args;

	va_start(args, format);

	for (; *ptr != '\0'; ++ptr)
	{
		if (*ptr == '%')
		{
			++ptr;
			switch (*ptr)
			{
				case 'd':
					count += printf("%d", va_arg(args, int));
					break;
				case 'f':
					count += printf("%f", va_arg(args, double));
					break;
				case 'c':
					count += printf("%c", va_arg(args, int));
					break;
				case 's':
					count += printf("%s", va_arg(args, char *));
					break;
				default:
					_putc(*ptr); /* Print any unrecognized specifier as is */
					++count;
			}
		}
		else
		{
			_putc(*ptr);
			++count;
		}
	}
	va_end(args);
	return (count);
}
