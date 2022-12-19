/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 04:52:40 by asaadane          #+#    #+#             */
/*   Updated: 2022/12/19 01:19:32 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_check_symb(const char *str, va_list num_args, size_t i, int *lenght)
{
	if (str[i] == 'c')
		ft_put_char(va_arg(num_args, int), lenght);
	else if (str[i] == 's')
		ft_put_str(va_arg(num_args, char *), lenght);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_put_nbr(va_arg(num_args, int), lenght);
	else if (str[i] == 'u')
		ft_put_unbr(va_arg(num_args, unsigned int), lenght);
	else if (str[i] == 'x')
		ft_put_lowhex(va_arg(num_args, unsigned int), lenght);
	else if (str[i] == 'X')
		ft_put_uphex(va_arg(num_args, unsigned int), lenght);
	else if (str[i] == 'p')
	{
		ft_put_str("0x", lenght);
		ft_put_ptr(va_arg(num_args, unsigned long ), lenght);
	}
	else
		ft_put_char(str[i], lenght);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int		lenght;
	va_list	num_args;

	i = 0;
	lenght = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(num_args, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_put_char(str[i], &lenght);
		else if (str[i + 1] == '\0')
			return (lenght);
		else
		{
			i++;
			ft_check_symb(str, num_args, i, &lenght);
		}
		i++;
	}
	va_end(num_args);
	return (lenght);
}
