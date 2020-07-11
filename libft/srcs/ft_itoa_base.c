/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 01:27:04 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/29 20:30:24 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static size_t	digit_count(long nb, int base)
{
	size_t		i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

static int		help_itoa(long int *taille, long int *i,
		char **ret, long int sign)
{
	*taille += (sign ? 1 : 0);
	*ret = (char *)malloc(sizeof(char) * (*taille + 1));
	*i = 1;
	sign ? (*ret[0] = '-') : 0;
	return (0);
}

static int		help2(long int *sign, int base, long int value)
{
	sign = 0;
	if (base == 10 && value < 0)
		*sign = 1;
	if (value < 0)
		value = -value;
	if (value == 0)
		return (0);
	return (1);
}

char			*ft_itoa_base(long int value, int base, char x)
{
	char			*ret;
	char			*tab_base;
	long int		taille;
	long int		i;
	long int		sign;

	if (base < 2 || base > 16)
		return (0);
	if (base == 10 && value == (-9223372036854775807 - 1))
		return ("-9223372036854775808");
	if (help2(&sign, base, value) == 0)
		return ("0");
	if (x == 'X')
		tab_base = "0123456789ABCDEF";
	else
		tab_base = "0123456789abcdef";
	taille = digit_count(value, base);
	help_itoa(&taille, &i, &ret, sign);
	while (value != 0)
	{
		ret[taille - i++] = tab_base[value % base];
		value /= base;
	}
	ret[taille] = '\0';
	return (ret);
}
