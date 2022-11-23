/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:02:21 by asaadane          #+#    #+#             */
/*   Updated: 2022/11/21 00:06:42 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	newline;

	newline = '\n';
	write(fd, s, ft_strlen(s));
	write(fd, &newline, 1);
}

// int main(){
// 	int fd = open("ft_putendl_fd.txt", O_CREAT | O_RDWR, 777);
// 	char str[]= "hello world..!";
// 	ft_putendl_fd(str, fd);
// }
// s[i] = i[s]

// s[i] = *(s + i) = *(i + s) =i[s]