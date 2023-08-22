#include "main.h"
/**
 * power - Calculates the power of a number.
 * @base: The base number.
 * @exponent: The exponent.
 * Return: The result of base raised to the power of exponent.
 */
int power(int base, int exponent)
{
	int i, result = 1;

	for (i = 0; i < exponent; i++)
	{
		result *= base;
	}
	return (result);
}
