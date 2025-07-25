#ifndef MAIN_H  // Include guard start
#define MAIN_H
#include <stdlib.h>
#include <limits.h>
// Function prototypes
int _printf(char *format, ...);
int _putchar(char c);
int print_num(int num);
int str_len(char *s);
int print_float(double num, int precision);
int print_reverse(char *s);
int print_octal(unsigned int num);
int print_unsigned(unsigned int num);
int print_binary(unsigned int num);
int print_hex(unsigned int num);
int print_upper_hex(unsigned int num);
int print_pointer(void *ptr);
#endif 
