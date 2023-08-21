#include <stdint.h>
#include "main.h"
#define BUFFER_SIZE 1024
/**
 * print_ints - print integers
 * @count: input count
 * Return: no return
 */
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
