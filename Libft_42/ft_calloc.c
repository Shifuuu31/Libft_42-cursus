/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:01:44 by asaadane          #+#    #+#             */
/*   Updated: 2022/11/21 20:05:31 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, count * size);
	return (ptr);
}
// int main()
// {
// 	int str[11] = {1,2,3};
// 	int *ptr;
// 	ptr = ft_calloc(11, sizeof(int));
// 	free(ptr);
// 	printf("%d", *(int *)(ptr + 2));
// 	// ft_memcpy(ptr,str,3);
// }