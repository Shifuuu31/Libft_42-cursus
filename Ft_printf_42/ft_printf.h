#ifndef FT_PRINTF_H
# define FT_PRINTF_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


int ft_abs(int nbr);
int lenght_num(int nbr);
char    *ft_itoa(int n);
int ft_printpercent(void);
int ft_putchar(int c);
int ft_putstr(char *str);
int ft_printnbr(int n);
int ft_checkformats(va_list args, const char format);
int ft_printf(const char *str, ...);
int lenght_hex(unsigned	int num);
void    ft_althex(unsigned int num, const char format);
int ft_puthex(unsigned int num, const char format);
int lenght_ptr(unsigned long long num);
void    ft_altptr(unsigned long long num);
int ft_print_ptr(unsigned long long ptr);
unsigned int lenght_nums(unsigned	int num);
unsigned int ft_putunsigned(unsigned int n);

#endif