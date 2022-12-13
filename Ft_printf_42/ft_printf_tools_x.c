/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:22:59 by asaadane          #+#    #+#             */
/*   Updated: 2022/12/13 08:24:15 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*--------------------------------------------------------*/
/* "ft_printf_tools_x": this file ".c" contains 
a multiple tools to help the main function "ft_printf.c"*/
/*--------------------------------------------------------*/

/*This function allows to print lowercase hexadecimal numbers*/
void	ft_put_lowhex(unsigned int num, int *lenght)
{
	const char	*basex;

	basex = "0123456789abcdef";
	if (num < 16)
		ft_put_char(basex[num], lenght);
	else
	{
		ft_put_lowhex((num / 16), lenght);
		ft_put_char(basex[num % 16], lenght);
	}
}

/*This function allows to print uppercase hexadecimal numbers*/
void	ft_put_uphex(unsigned int num, int *lenght)
{
	const char	*basexx;

	basexx = "0123456789ABCDEF";
	if (num < 16)
		ft_put_char(basexx[num], lenght);
	else
	{
		ft_put_uphex((num / 16), lenght);
		ft_put_char(basexx[num % 16], lenght);
	}
}

/*This function allows to print pointers hexadecimale addresses*/
void	ft_put_ptr(unsigned long num, int *lenght)
{
	const char	*basex;

	basex = "0123456789abcdef";
	if (num >= 16)
		ft_put_ptr((num / 16), lenght);
	ft_put_char(basex[num % 16], lenght);
}
