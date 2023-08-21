#ifndef _MAIN_H_
#define _MAIN_H_


#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struct format - struct for format specifiers
 * @fs: format specifiers
 * @fp: function pointers
 * @sp_char:special characters
 */
typedef struct f_spec
{
	char fs;
	int (*f)();
} sp_char;

int _printf(const char *format, ...);
int _putc(char c);
int _benedict(const char *c);
int printf_str(va_list argmt);
int printf_percent(void);
int printf_char(va_list argmt);


#endif /* _MAIN_H_ */
