/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:57:44 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/17 18:04:52 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*d;
	char	*s;
	char	temp;

	d = (char *)dst;
	s = (char *)src;
	temp = c;
	while (n--)
	{
		*d++ = *s++;
		if (*(d - 1) == temp)
			return (d);
	}
	return (NULL);
}
