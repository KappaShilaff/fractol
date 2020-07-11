/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:07:08 by lcassaun          #+#    #+#             */
/*   Updated: 2019/10/16 22:01:54 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_strchr(const char *str, int ch)
{
	size_t		i;

	i = 0;
	if ((char)ch == '\0')
		return (NULL);
	while (str[i])
		if (str[i++] == (char)ch)
			return ((char *)&str[i - 1]);
	return (0);
}
