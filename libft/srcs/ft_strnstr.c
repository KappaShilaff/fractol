/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:22:33 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/19 19:44:16 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	if (!*str2)
		return ((char *)str1);
	while (*str1 && n)
	{
		if (*str1 == str2[0])
		{
			i = 0;
			if (!(*str2 + 1))
				return ((char *)(str1));
			while (str1[i] == str2[i] && n - i)
			{
				i++;
				if (!str2[i])
					return ((char *)str1);
			}
		}
		str1++;
		n--;
	}
	return (NULL);
}
