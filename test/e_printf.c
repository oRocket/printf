#include "main.h"
#define BUFFER_SIZE 1024
/**
 * custom_snprintf - Emulates a simplified version of snprintf.
 * @str: Destination buffer for the formatted output.
 * @size: Size limit of the destination buffer.
 * @format: Format string specifying the desired output format.
 * Return: The number of characters.
 */
int custom_snprintf(char *str, size_t size, const char *format, ...)
{
	char buffer[BUFFER_SIZE];
	int chars_w = vsnprintf(buffer, BUFFER_SIZE, format, args);
	va_list args;

	va_start(args, format);

	va_end(args);

	if (chars_w < 0) /* character written */
	{
		return (-1); /* error */
	}

	if ((size_t)chars_w < size)
	{
		strncpy(str, buffer, size);
		_benedict(str); /* print the result */
		return (chars_w);
	}
	else
	{
		strncpy(str, buffer, size - 1);
		str[size - 1] = '\0';
		_benedict(str); /* print the result */
		return (size - 1);
	}
}

