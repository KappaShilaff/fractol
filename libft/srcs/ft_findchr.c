/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 01:23:48 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/28 01:23:50 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_findchr(const char *str, int s)
{
	long int	i;

	i = 0;
	while (*str != (char)s && *str != '\0')
	{
		++str;
		++i;
	}
	if (*(str) == (char)s)
		return (i);
	return (-1);
}
