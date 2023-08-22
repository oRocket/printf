#include "main.h"
/**
 * _albert - Custom printf implementation.
 * @format: The format string.
 * @...: Variable number of arguments based on format.
 * Return: The number of characters written.
 */
int _albert(const char *format, ...)
{
	int w_chars = 0, num, num_digits; /* written character */
	const char *p = format;
	char *num_str;
	va_list args;

	va_start(args, format);

	while (*p != '\0')
	{
		if (*p == '%' && (*(p + 1) == 'd' || *(p + 1) == 'i'))
		{
			p++;
			num = va_arg(args, int);
			num_digits = count_digits(num);

			num_str = (char *)malloc(num_digits + 1);
			if (num_str == NULL)
			{
				va_end(args);
				return (-1);
			}

			snprintf(num_str, num_digits + 1, "%d", num);
			write(STDOUT_FILENO, num_str, num_digits);
			w_chars += num_digits;
			free(num_str);
		}
		else
		{
			write(STDOUT_FILENO, p, 1);
			w_chars++;
		}
		p++;
	}
	va_end(args);
	return (w_chars);
}
