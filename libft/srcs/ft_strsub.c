/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:51:49 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/20 17:06:16 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*strnew;
	unsigned int	i;

	i = 0;
	if (!(strnew = ft_strnew(len)) || !s)
		return (NULL);
	while (len--)
		strnew[i++] = s[start++];
	strnew[i] = '\0';
	return (strnew);
}
