#include "main.h"
#include <stdio.h>
/**
 * _printf - print to std format
 * @f: format
 * Return: number of bytes to be printed
 */
int printf_int(const char *f, ...)
{
	unsigned int a, count = 0, num;
	va_list argumts;

	if (!f || (f[0] == '%' && f[1] == '\0'))
	{
		return (-1);
	}
	va_start(argumts, f);

	for (a = 0; f[a] != '\0'; a++)
	{
		if (f[a + 1] == 'd')
		{
			num = va_arg(argumts, int);
			printf("Signed:[%d]\n", num);
			a += 1;
		}
		else if (f[a + 1] == 'u')
		{
			num = va_arg(argumts, unsigned int);
			printf("Unsigned:[%u]\n", num); /* Print the unsigned integer */
			a += 1;
		}
		else if (f[a + 1] == 'o')
		{
			num = va_arg(argumts, unsigned int);
			printf("Unsigned octal:[%o]\n", num); /* Print the octal number */
			a += 1;
		}
		else if (f[a + 1] == 'x')
		{
			num = va_arg(argumts, unsigned int);
			printf("Unsigned hexadecimal:[%x, %X]\n", num, num);
			a += 1;
		}
		else if (f[a + 1] == 'p')
		{
			void *ptr = va_arg(argumts, void *);
			printf("Address:[%p]\n", ptr); /* Print the memory address */
			a += 1;
		}
		else if (f[a + 1] == '%')
		{
			_putc('%');
			a += 1;
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