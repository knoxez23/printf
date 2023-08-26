#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int _printf(const char *format, ...);
int print_int(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args, int uppercase);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);
int print_binary(va_list args);
int print_memory_address(va_list args);

#endif
