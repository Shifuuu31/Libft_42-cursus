/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:04:50 by asaadane          #+#    #+#             */
/*   Updated: 2022/11/22 17:07:28 by asaadane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void p(unsigned int i ,char *p)
// {
// 	i = 32;
// 	*p -= i;
// }
// int main()
// {
// 	char str[] = "hello";
// 	ft_striteri(str,p);
// 	printf("%s",str);
// }