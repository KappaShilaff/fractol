/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:08:18 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/20 17:23:00 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strnew;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	if (!(strnew = ft_chmalloc_zend(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	temp = strnew;
	while (*s1)
		*temp++ = (char)*s1++;
	while (*s2)
		*temp++ = (char)*s2++;
	return (strnew);
}
