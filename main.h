#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);

void print_char(va_list param, int *calc);

void print_string(va_list param, int *calc);

void print_percent(int *calc);

int _printf(const char *format, ...);

void print_int(va_list param, int *calc);

void process_format(const char **format, va_list param, int *calc);




#endif

