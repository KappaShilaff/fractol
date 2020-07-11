/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:41:56 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/19 18:22:57 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

char	*ft_strrchr(const char *str, int ch)
{
	long int	len;

	len = ft_strlen(str);
	if (ch == 0)
		return ((char *)&str[len]);
	len--;
	while (str[len] && len >= 0)
	{
		if (str[len] == (char)ch)
			return ((char *)&str[len]);
		len--;
	}
	return (0);
}
