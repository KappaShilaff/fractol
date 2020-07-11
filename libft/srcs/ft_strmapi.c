/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:13:05 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/20 16:17:41 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstr;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(newstr = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		newstr[i] = (*f)(i, s[i]);
		i++;
	}
	return (newstr);
}
