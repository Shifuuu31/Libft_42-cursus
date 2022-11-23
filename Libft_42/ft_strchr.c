/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:02:29 by asaadane          #+#    #+#             */
/*   Updated: 2022/11/21 20:22:14 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char )c)
		return ((char *)str + i);
	return (0);
}
// int main () {
//    const char str[] = "es for srchr funcion";
// //    const char ch = 'f';
//    printf("%s\n", ft_strchr(str, 't'));
//    return(0);
// }
