/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:22:49 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/24 17:44:13 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *elem;

	if (!(elem = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content || !content_size)
	{
		elem->content = (void *)0;
		elem->content_size = 0;
	}
	else
	{
		if (!(elem->content = ft_memalloc(content_size)))
		{
			free(elem);
			return (NULL);
		}
		elem->content_size = content_size;
		ft_memcpy(elem->content, content, content_size);
	}
	elem->next = NULL;
	return (elem);
}
