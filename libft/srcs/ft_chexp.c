/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chexp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 01:25:35 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/28 01:26:20 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_chexp(char *str, size_t n)
{
	char	*res;
	char	*buf;
	char	*value;

	value = ft_strdup(str);
	if (n == 0)
		return (ft_strdup("1.0"));
	res = ft_strdup("1.0");
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			buf = res;
			res = ft_chmult(res, value);
			free(buf);
		}
		buf = value;
		value = ft_chmult(value, value);
		free(buf);
		n /= 2;
	}
	free(value);
	return (res);
}
