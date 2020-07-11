/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:00:59 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/20 16:19:37 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*temp;
	char	*newstr;

	if (!s || !f)
		return (NULL);
	if (!(newstr = ft_strnew(ft_strlen(s))))
		return (NULL);
	temp = newstr;
	while (*s)
		*temp++ = (*f)(*s++);
	return (newstr);
}
