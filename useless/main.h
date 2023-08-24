#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#define BUFFER_SIZE 1024
#define FLAG_PLUS (1 << 0)
#define FLAG_SPACE (1 << 1)
#define FLAG_HASH (1 << 2)

void handle_HEX(va_list args, int *count, int flags, int length_modifier);
void handle_hex(va_list args, int *count, int flags, int length_modifier);
void handle_decimal(va_list args, int *count, int flags, int length_modifier);
void handle_unsint(va_list args, int *count, int flags, int length_modifier);
void handle_decimal(va_list args, int *count, int flags, int length_modifier);
int print_short_decimal(va_list args, int *count, int flags);
int print_long_decimal(va_list args, int *count, int flags);
int print_short_decimal(va_list args, int *count, int flags);
int print_long_unsint(va_list args, int *count, int flags);
int print_short_unsint(va_list args, int *count, int flags);
int print_short_oct(va_list args, int *count, int flags);
int print_long_oct(va_list args, int *count, int flags);
int print_short_hex(va_list args, int *count, int flags);
int print_long_hex(va_list args, int *count, int flags);
int print_short_HEX(va_list args, int *count, int flags);
int print_long_HEX(va_list args, int *count, int flags);
int _string(char *str, int length);
int print_address(va_list args, int *count);
int print_hexad(unsigned long int n, int *count);
int print_unsint(va_list args, int *count);
int print_HEX(va_list args, int *count);
int print_hex(va_list args, int *count);
int print_oct(va_list args, int *count);
int print_decimal(va_list args, int *count);
int print_string(va_list args, int *count);
int print_char(va_list args, int *count);
int power(int base, int exponent);
int _print_int(va_list argumts);
int _printf(const char *format, ...);
int _benedict(const char *c);
int _putc(char c);
#endif /* MAIN_H */
