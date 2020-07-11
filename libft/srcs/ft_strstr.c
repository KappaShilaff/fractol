/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:53:30 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/19 17:00:58 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_strstr(const char *str1, const char *str2)
{
	char	*stra;
	char	*strb;
	int		i[3];

	stra = (char *)str1;
	strb = (char *)str2;
	i[0] = 0;
	if (!*str2)
		return ((char *)str1);
	while (stra[i[0]] == '\0')
		i[0]++;
	while (stra[i[0]])
		if (stra[i[0]++] == strb[0])
		{
			i[1] = 0;
			i[2] = i[0] - 1;
			while (stra[i[1]] && (strb[i[1]++] == stra[i[2]++]))
				if (!strb[i[1]])
					return (stra + i[0] - 1);
		}
	return (0);
}
