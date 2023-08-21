#include "main.h"
/**
 * _printf - function that supports %c, %s, and %%.
 * @format: format specifier.
 * Return: printed chars.
 */
int _printf(const char *format, ...)
{
	int count = 0; /* character count initialization */
	char c; /* variable to hold character */
	const char *s; /* string pointer */
	va_list my_format; /* va_list declared to hold variable argument */

	va_start(my_format, format); /* variable argument processing started */
	for (; *format; format++) /* loop through each character in format string */
	{
		if (*format == '%') /* checking if the character is a percent sign */
		{
			format++; /* moving to the next character after the percent sign */
			switch (*format)
			{
				case 'c': /* if format specifier is %c */
					c = va_arg(my_format, int);
					write(STDOUT_FILENO, &c, 1); /* writing the character to stdout */
					count++;
					break;
				case 's': /* if format specifier is %s */
					s = va_arg(my_format, const char *);
					for (; *s; s++) /* loop through the characters in the string */
					{
						write(STDOUT_FILENO, s, 1); /* writing each character to stdout */
						count++;
					}
					break;
				case '%': /* if format specifier is %% */
					write(STDOUT_FILENO, "%", 1); /* writing the percent sign to stdout */
					count++;
					break;
			}
		}
		else
		{
			write(STDOUT_FILENO, format, 1); /* writing the character to stdout */
			count++;
		}
	}
	va_end(my_format); /* end variable argument processing */
	return (count); /* Return the total number of characters printed */
}
