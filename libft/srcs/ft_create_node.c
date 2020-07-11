/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:23:57 by lcassaun          #+#    #+#             */
/*   Updated: 2019/11/12 15:24:00 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_create_node(void *data)
{
	t_node	*t;

	if (!(t = malloc(sizeof(t_node))))
		return (NULL);
	ft_bzero(t, sizeof(t_node));
	t->d = data;
	t->c = RED;
	t->l = NULL;
	t->r = NULL;
	t->p = NULL;
	return (t);
}
