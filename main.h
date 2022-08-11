#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct fmt - function to check for formats
 * @type: The format to print
 * @f: The print function to use
 */
typedef struct fmt
{
	char *type;
	int (*f)();
} fmt_t;

int _printf(const char *format, ...);
int print_op(const char *format, fmt_t *print_arr, va_list list);
int ch(va_list character);
int str(va_list string);
int _putchar(char c);
int _int(va_list integer);
int _bin(va_list binary);
int _uint(va_list unsign);
int _uoct(va_list oct);
int _lowhex(va_list hexadecimal);
int _uphex(va_list hexadecimal);
int _rot13(va_list rot);

#endif
