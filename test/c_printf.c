#include "main.h"
#include <stdio.h>

/**
 * _printf - print to std format
 * @format: format
 * Return: number of bytes to be printed
 */
int _printf(const char *format, ...)
{
    unsigned int a, count = 0, count_s;
    va_list argumts;

    if (!format || (format[0] == '%' && format[1] == '\0'))
    {
        return (-1);
    }
    va_start(argumts, format);

    for (a = 0; format[a] != '\0'; a++)
    {
        if (format[a] != '%')
        {
            _putc(format[a]);
            putchar(format[a]); // Print the character
        }
        else if (format[a + 1] == 'c')
        {
            _putc(va_arg(argumts, int));
            putchar(va_arg(argumts, int)); // Print the character
            a += 1;
        }
        else if (format[a + 1] == 's')
        {
            const char *str = va_arg(argumts, const char *);
            count_s = _benedict(str);
            a += 1;
            count += (count_s - 1);

            printf("String:[%s]\n", str); // Print the string
        }
        else if (format[a + 1] == 'd')
        {
            int num = va_arg(argumts, int);
            printf("Signed:[%d]\n", num); // Print the signed integer
            a += 1;
        }
        else if (format[a + 1] == 'u')
        {
            unsigned int num = va_arg(argumts, unsigned int);
            printf("Unsigned:[%u]\n", num); // Print the unsigned integer
            a += 1;
        }
        else if (format[a + 1] == 'o')
        {
            unsigned int num = va_arg(argumts, unsigned int);
            printf("Unsigned octal:[%o]\n", num); // Print the octal number
            a += 1;
        }
        else if (format[a + 1] == 'x')
        {
            unsigned int num = va_arg(argumts, unsigned int);
            printf("Unsigned hexadecimal:[%x, %X]\n", num, num); // Print the hexadecimal number
            a += 1;
        }
        else if (format[a + 1] == 'p')
        {
            void *ptr = va_arg(argumts, void *);
            printf("Address:[%p]\n", ptr); // Print the memory address
            a += 1;
        }
        else if (format[a + 1] == '%')
        {
            _putc('%');
            putchar('%'); // Print a literal percent sign
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

// You can define the _putc and _benedict functions here

int main(void)
{
    _printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d, %i]\n", 39, 39);
    _printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", 2147484671);
    _printf("Unsigned octal:[%o]\n", 20000001777);
    _printf("Unsigned hexadecimal:[%x, %X]\n", 800003ff, 800003FF);
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", (void *)0x7ffe637541f0);
    _printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", 12);
    _printf("Unknown:[%r]\n");

    return (0);
}

