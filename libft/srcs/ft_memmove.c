/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:05:02 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/19 15:27:43 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (d < s)
		while (n-- && (src || dst))
			*d++ = *s++;
	else
	{
		d += n;
		s += n;
		while (n-- && (src || dst))
			*--d = *--s;
	}
	return (dst);
}
