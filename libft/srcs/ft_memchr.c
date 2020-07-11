/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:21:15 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/17 18:06:22 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	*ft_memchr(const void *arr, int c, size_t n)
{
	char	*ar;
	char	temp;

	ar = (char *)arr;
	temp = c;
	while (n--)
	{
		if (*ar == temp)
			return (ar);
		ar++;
	}
	return (NULL);
}
