#ifndef FT_PRINTF_H
# define FT_PRINTF_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int		ft_printf(const char *str, ...);

void	ft_put_char(char c, int *lenght);
void	ft_put_str(char *str, int *lenght);
void	ft_put_nbr(int num, int *lenght);
void	ft_put_unbr(unsigned int num, int *lenght);
void	ft_put_lowhex(unsigned int num, int *lenght);
void	ft_put_uphex(unsigned int num, int *lenght);
void	ft_put_ptr(unsigned long long num, int *lenght);

#endif