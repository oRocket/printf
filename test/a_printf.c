#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int printf(const char *format, ...)
{
	int ca = 0;
	const char *p = format;
	va_list args;

	va_start(args, format);

	while (*p != '\0')
	{
		if (*p == '%')
		{
			p++;
			if (*p == 'c')
			{
				char c = (char) va_arg(args, int);
				write(STDOUT_FILENO, &c, 1);
				ca++;
			}
			else if (*p == 's')
			{
				char *str = va_arg(args, char *);
				while (*str != '\0')
				{
					write(STDOUT_FILENO, str, 1);
					str++;
					ca++;
				}
			}
			else if (*p == '%')
			{
				write(STDOUT_FILENO, "%", 1);
				ca++;
			}
		}
		else
		{
			write(STDOUT_FILENO, p, 1);
			ca++;
		}
		p++;
	}
	va_end(args);
	return (ca);
}
