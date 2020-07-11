/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memstrncpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:12:18 by lcassaun          #+#    #+#             */
/*   Updated: 2019/11/12 15:12:20 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memstrncpy(char *new, const char *str, size_t i)
{
	new = ft_chmalloc_zend(i);
	new = ft_strncpy(new, str, i);
	return (new);
}
