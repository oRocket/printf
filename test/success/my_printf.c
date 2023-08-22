#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _putchar(char c)
{
	return (_write(1, &c, 1)); /* 1 is the file descriptor for stdout */
}

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
					break;
				case 'i':
					break;
				case 'f':
					break;
				case 'c':
					break;
				case 's':
					break;
				default:
					_putchar(*ptr);
					++count;
			}
		}
		else
		{
			_putchar(*ptr);
			++count;
		}
	}
	va_end(args);
	return (count);
}

