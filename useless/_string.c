#include "main.h"
/**
 * _string - Prints a string
 * @str: String pointer
 * @length: String length
 * Return: 1 if successful, otherwise -1
 */
int _string(char *str, int length)
{
	return (write(1, str, length));
}
