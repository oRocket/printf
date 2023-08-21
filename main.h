#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int _albert(const char *format, ...); 
int count_digits(int num);
int _benedict(const char *c);
int print_integer(va_list args);
int _printf(const char *format, ...);
int _putc(char c);

#endif
