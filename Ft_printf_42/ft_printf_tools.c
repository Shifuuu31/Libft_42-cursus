/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 04:52:29 by asaadane          #+#    #+#             */
/*   Updated: 2022/12/18 23:01:43 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*--------------------------------------------------------*/
/* "ft_printf_tools": this file ".c" contains 
a multiple tools to help the main function "ft_printf.c"*/
/*--------------------------------------------------------*/

/*This function allows to print a single Character*/
void	ft_put_char(char c, int *lenght)
{
	write(1, &c, 1);
	*lenght += 1;
}

/*This function allows to print a String*/
void	ft_put_str(char *str, int *lenght)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_put_str("(null)", lenght);
		return ;
	}
	while (str[i])
	{
		ft_put_char(str[i], lenght);
		i++;
	}
}

/*This function allows to print numbers*/
void	ft_put_nbr(int num, int *lenght)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
			*lenght += 11;
		return ;
	}
	else if (num < 0)
	{
		ft_put_char('-', lenght);
		num *= -1;
	}
	if (num <= 9)
		ft_put_char((num + 48), lenght);
	else
	{
		ft_put_nbr((num / 10), lenght);
		ft_put_char((num % 10) + 48, lenght);
	}
}

/*This function allows to print unsigned numbers*/
void	ft_put_unbr(unsigned int num, int *lenght)
{
	if (num >= 10)
	{
		ft_put_unbr((num / 10), lenght);
		ft_put_char((num % 10) + 48, lenght);
	}
	else
		ft_put_char((num + 48), lenght);
}
