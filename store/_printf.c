#include "main.h"

int _printf(const char *format, ...)
{
	int digits = 0;
	int i;
	int num;
	int temp;
	int hex_digits;
	int length;
	unsigned int hex_num;
	unsigned int octal_num;
	unsigned int unsigned_num;

	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			_putc(*format);
			count++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					_putc(va_arg(args, int));
					count++;
					break;
				case 's':
					{
						char *str = va_arg(args, char *);
						while (*str != '\0')
						{
							_putc(*str);
							str++;
							count++;
						}
						break;
					}
				case '%':
					_putc('%');
					count++;
					break;
				case 'd':
				case 'i':
					{
						num = va_arg(args, int);
						if (num < 0)
						{
							_putc('-');
							count++;
							num = -num;
						}
						temp = num;
						do
						{
							temp /= 10;
							digits++;
						}
						while (temp > 0);
						while (digits > 0)
						{
							_putc('0' + (num / power(10, digits - 1)) % 10);
							count++;
							digits--;
						}
						break;
					}
				case 'r':
					{
						char *str = va_arg(args, char *);
						length = 0;
						while (str[length] != '\0')
							length++;

						while (length > 0)
						{
							length--;
							_putc(str[length]);
							count++;
						}
						break;
					}
				case 'u':
					{
						unsigned_num = va_arg(args, unsigned int);
						temp = unsigned_num;
						do
						{
							temp /= 10;
							digits++;
						}
						while (temp > 0);
						
						while (digits > 0)
						{
							_putc('0' + (unsigned_num / power(10, digits - 1)) % 10);
							count++;
							digits--;
						}
						break;
					}
				case 'o':
					{
						octal_num = va_arg(args, unsigned int);
						temp = octal_num;
						do
						{
							temp /= 8;
							digits++;
						}
						while (temp > 0);

						while (digits > 0)
						{
							_putc('0' + (octal_num / power(8, digits - 1)) % 8);
							count++;
							digits--;
						}
						break;
					}
				case 'x':
					{
						hex_num = va_arg(args, unsigned int);
						hex_digits = 1; /* At least one digit */
						
						while (hex_num >= 16)
						{
							hex_num /= 16;
							hex_digits++;
						}
						_putc('0');
						_putc('x');
						count += 2;
						
						for (i = hex_digits - 1; i >= 0; i--)
						{
							_putc("0123456789abcdef"[(va_arg(args, unsigned int) >> (4 * i)) & 0xf]);
							count++;
						}
						break;
					}
				default:
					_putc('%');
					_putc(*format);
					count += 2;
			}
		}
		format++;
	}

	va_end(args);
	return (count);
}
