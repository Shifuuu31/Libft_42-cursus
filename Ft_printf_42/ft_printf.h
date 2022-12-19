/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 04:52:49 by asaadane          #+#    #+#             */
/*   Updated: 2022/12/16 05:17:42 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	ft_put_char(char c, int *lenght);
void	ft_put_str(char *str, int *lenght);
void	ft_put_nbr(int num, int *lenght);
void	ft_put_unbr(unsigned int num, int *lenght);
void	ft_put_lowhex(unsigned int num, int *lenght);
void	ft_put_uphex(unsigned int num, int *lenght);
void	ft_put_ptr(unsigned long num, int *lenght);

#endif