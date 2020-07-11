/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cont_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:24:27 by lcassaun          #+#    #+#             */
/*   Updated: 2019/11/12 17:27:29 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cont	*ft_create_cont_fd(int fd)
{
	t_cont	*t;

	if (!(t = malloc(sizeof(t_cont))))
		return (NULL);
	ft_bzero(t, sizeof(t_cont));
	t->fd = fd;
	return (t);
}
