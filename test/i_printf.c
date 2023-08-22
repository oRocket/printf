#include <stdint.h>
#include "main.h"
#define BUFFER_SIZE 1024

void print_ints(int count, ...)
{
	int i = 0, value, length, j = 0;
	char buffer[BUFFER_SIZE];
	va_list args;

	va_start(args, count);

	if (count < 0)
	{
		printf("Error: count must be non-negative.\n");
		return;
	}

	for (i = 0; i < count; i++)
	{
		value = va_arg(args, int);

		length = snprintf(buffer, sizeof(buffer), "%i\n", value);

		for (j = 0; j < length; j++)
		{
			_putc(buffer[j]);
		}
	}
	va_end(args);
}
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
