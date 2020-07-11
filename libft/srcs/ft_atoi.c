/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:03:15 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/24 20:57:48 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char const *str)
{
	unsigned long long		result;
	size_t					i;
	char					sign;

	result = 0;
	i = 0;
	sign = 0x2b;
	while (i[str] == 32 || (i[str] >= 9 && i[str] <= 13))
		i++;
	sign = str[i];
	if (str[i] == 0x2d || str[i] == 0x2b)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	if (sign == 0x2d && result <= 9223372036854775808UL)
		return (result * -1);
	else if (sign != 0x2d && result <= 9223372036854775807)
		return (result);
	else if (sign != 0x2d)
		return (-0x1);
	return (!!!0b101);
}
