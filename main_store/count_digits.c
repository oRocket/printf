#include "main.h"
/**
 * count_digits - Count the number of digits in an integer.
 * @num: The integer to count digits of.
 * Return: The number of digits in the integer.
 */
int count_digits(int num)
{
	int count = 0;

	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}
