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
 * struct fmt - Format Specification Structure
 *
 * This structure represents a format specification used for
 * handling various data
 * formatting operations in C. It contains two members: 'fmt' and 'fn'.
 *
 * @fmt: The format character, typically specifying the type of data to format.
 * @fn: A function pointer that points to a function
 * responsible for formatting data of the specified type.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef formt_t - Typedef for Format Specification Structure
 *
 * This typedef provides an alias 'fmt_t' for the 'struct fmt' data structure,
 * making it easier to declare variables of this type.
 *
 * @fmt: The format character, typically specifying the type of data to format.
 * @fn: A function pointer that points to a function responsible for formatting
 * data of the specified type.
 */
typedef struct fmt formt_t;

int _printf(const char *format, ...);
	int trigger_print(const char *fmt, int *j,
va_list list, char buffer[], int flag, int wid, int fmt_prec, int size);

int _printf(const char *format, ...);

void print_buffer(char buffer[], int *buff_idx);

int print_char(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size);

int print_string(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size);

int print_per_cent(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size);

int print_intgrs(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size);

int print_bi_nary(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size);

int print_nonsigned(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size);

int print_octal(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size);

int hexadecimal_funct(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size);

int print_higher_hexa(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size);

int print_hexa(va_list param, char map_to[], char buffer[],
	int flag, char flag_ch, int wid, int fmt_prec, int size);

int pointer_variant(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size);

int non_printable(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size);

int reverse_funct(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size);

int rot_13string(va_list param, char buffer[],
	int flag, int wid, int fmt_prec, int size);

int call_size(const char *format, int *j);

int call_flags(const char *format, int *j);

int call_precision(const char *format, int *j, va_list param);
	int get_size(const char *format, int *j);

int call_width(const char *format, int *j, va_list param);

int trigger_print(const char *fmt, int *idx, va_list param,
	char buffer[], int flag, int wid, int fmt_prec, int size);

int is_print_ble(char c);

int append_hex_code(char ascii_code, char buffer[], int j);

long int convert_number_size(long int num, int size);

long int convert_unsyned(unsigned long int num, int size);

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

