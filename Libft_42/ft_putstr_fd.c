/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:02:25 by asaadane          #+#    #+#             */
/*   Updated: 2022/11/22 15:21:42 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

// int main(){
// 	int fd = open("ft_putstr_fd.txt", O_CREAT | O_RDWR, 777);
// 	char str[]= "hello world..!";
// 	ft_putstr_fd(str, fd);
// }