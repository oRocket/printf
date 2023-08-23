#include "main.h"

void print_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			printf("\\x%02X", str[i]);
		}
		else
		{
			printf("%c", str[i]);
		}
		i++;
	}
}

void print_formatted_string(char *format, ...)
{
	int i = 0;
	va_list args;

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[++i])
			{
				case 'S':
					print_string(va_arg(args, char *));
					break;
				default:
					_putc('%');
					_putc(format[i]);
					break;
			}
		}
		else
		{
			_putc(format[i]);
		}
		i++;
	}
	va_end(args);
}
