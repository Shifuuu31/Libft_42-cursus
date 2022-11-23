/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:02:16 by asaadane          #+#    #+#             */
/*   Updated: 2022/11/22 15:21:02 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main(){
// 	int fd = open("ft_putchar_fd.txt", O_CREAT | O_RDWR, 777);
// 	ft_putchar_fd('A', fd);
// }