/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:33:06 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/22 21:01:42 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *str1, const char *str2, size_t n)
{
	size_t	s1;
	size_t	s2;

	s1 = 0;
	s2 = ft_strlen(str2);
	if ((s2 + n) == 0)
		return (0);
	while (*str1 && n > 0)
	{
		s1++;
		str1++;
		n--;
	}
	while (*str2 && n-- > 1)
	{
		*str1++ = *str2++;
		if (n == 1 || *str2 == 0)
			*str1 = '\0';
	}
	return (s1 + s2);
}
