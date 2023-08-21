#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct op - Struct op
 *
 * @flags_t: The operator
 * @f: The function associated
 */
typedef struct print
{
	char *op;
	int (*f)(va_list, char *, unsigned int);
} op_t;

/**
 * struct op - Struct op
 *
 * @flags_t: The operator
 * @f: The function associated
 */
typedef struct 
{
	int d;
	int i;
} flags_t;

int _benedict(const char *c);
int print_integer(va_list args);
int _printf(const char *format, ...);
int _putc(char c);

#endif
