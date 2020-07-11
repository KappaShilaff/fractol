/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:02:16 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/19 20:07:14 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_numlen(long int n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(long int n)
{
	char	*str;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	i = ft_numlen(n) + 2;
	if (n == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	if (!(str = malloc(sizeof(char) * i--)))
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	else
		str[i--] = '\0';
	str[i] = '\0';
	while (n != 0)
	{
		i--;
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
