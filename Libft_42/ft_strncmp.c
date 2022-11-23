/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:02:48 by asaadane          #+#    #+#             */
/*   Updated: 2022/11/21 20:13:21 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == NULL)
		return (NULL);
	while (i < n - 1 && str1 && str2 && str1[i] == str2[i])
	{
		i++;
		if (!str1[i] || !str2[i])
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
// int main () {
//    char s1[]= "test";
//    char s2[]= "testss";
//     printf("%d\n", ft_strncmp(s2, s1,7));
// }