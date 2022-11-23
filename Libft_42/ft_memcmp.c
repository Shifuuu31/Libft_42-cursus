/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:02:03 by asaadane          #+#    #+#             */
/*   Updated: 2022/11/20 14:14:42 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str1)[i] != ((unsigned char *)str2)[i])
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		i++;
	}
	return (0);
}

// int main () {
//    int s1[] = {9};
//    char s2[]= "9";
//    int result;

//    result = ft_memcmp(s1, s2, 1);

//    if(result < 0) {
//       printf("string 1 is greater than string 2\n");
//    } else if(result > 0) {
//       printf("string 2 is greater than string 1\n");
//    } else {
//       printf("Both equal\n");
//    }
// }