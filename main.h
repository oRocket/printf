#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#define BUFFER_SIZE 1024

int _print(const char *format, ...);
void print_ints(int count, ...);
int _albert(const char *format, ...);
int count_digits(int num);
int _benedict(const char *c);
int print_integer(va_list args);
int _printf(const char *format, ...);
int printf_more_int(const char *f, ...);
int printf_int(const char *f, ...);
int _putc(char c);

#endif
