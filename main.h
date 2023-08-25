
#ifndef MAIN_H_
#define MAIN_H_
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
 
#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)
 
/* Sizes */
#define S_LONG 2
#define S_SHORT 1
 
/* Flags */
#define F_SUB 1
#define F_ADD 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
 
/**
 * struct fmt – Handles Struct covert operations
 * @fmt: The format string given in the main prototype
 * @fn: all function associated with the project
 */
 
struct fmt
{
        	char fmt;
        	int (*fn)(va_list, char[], int, int, int, int);
};
 
 
/**
 * typedef struct fmt fmt_t - Handles Struct covert operations
 * @fmt: The format string given in the main prototype
 * @fm_t: all function associated with the project
 */
 
typedef struct fmt fmt_t;
 
int _printf(const char *format, ...);
int trigger_print(const char *fmt, int *j,
va_list param, char buffer[], int flag, int wid, int fmt_prec, int size);
 
int _printf(const char *format, ...);
 
void print_buffer(char buffer[], int *buff_idx);
 
int print_char(va_list param, char buffer[],
int flag, int wid, int fmt_prec, int size);
 
int print_string(va_list param, char buffer[],
int flag, int wid, int fmt_prec, int size);
 
int print_percent(va_list param, char buffer[],
int flag, int wid, int fmt_prec, int size);
 
int print_int(va_list param, char buffer[],
int flag, int wid, int fmt_prec, int size);
 
int print_binary(va_list param, char buffer[],
int flag, int wid, int fmt_prec, int size);
 
int print_unsigned(va_list param, char buffer[],
int flag, int wid, int fmt_prec, int size);
 
int print_octal(va_list param, char buffer[],
int flag, int wid, int fmt_prec, int size);
 
int print_hexadecimal(va_list param, char buffer[],
int flag, int wid, int fmt_prec, int size);
 
int print_hexa_upper(va_list param, char buffer[],
int flag, int wid, int fmt_prec, int size);
 
int print_hexa(va_list param, char map_to[], char buffer[],
int flag, char flag_ch, int wid, int fmt_prec, int size);
 
int print_pointer(va_list param, char buffer[],
int flag, int wid, int fmt_prec, int size);
 
int print_non_printable(va_list param, char buffer[],
int flag, int wid, int fmt_prec, int size);
 
int print_reverse(va_list param, char buffer[],
int flag, int wid, int fmt_prec, int size);
 
int print_rot13string(va_list param, char buffer[],
        	int flag, int wid, int fmt_prec, int size);
 
int get_flags(const char *format, int *j);
 
int get_precision(const char *format, int *j, va_list param);
 
int get_size(const char *format, int *j);
 
int get_width(const char *format, int *j, va_list param);
 
int trigger_print(const char *fmt, int *idx, va_list param, char buffer[],
        	int flag, int wid, int fmt_prec, int size);
 
int is_printable(char c);
 
int append_hex_code(char ascii_code, char buffer[], int j);
 
long int convert_number_size(long int num, int size);
 
long int convert_unsigned(unsigned long int num, int size);
 
int handle_write_char(char c, char buffer[],
        	int flag, int wid, int fmt_prec, int size);
 
int write_number(int is_negative, int idx, char buffer[],
        	int flag, int wid, int fmt_prec, int size);
 
int write_num(int idx, char buffer[], int flag, int wid, int fmt_prec,
        	int length, char filler, char extra_c);
 
int write_unsgnd(int is_negative, int idx, char buffer[],
        	int flag, int wid, int fmt_prec, int size);
 
int write_pointer(char buffer[], int idx, int length,
        	int wid, int flag, char filler, char extra_c, int filler_start);
 
#endif /* MAIN_H_ */

