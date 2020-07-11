/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:21:36 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/24 20:12:54 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	if (!(temp = ft_lstnew((*f)(lst)->content, (*f)(lst)->content_size)))
		return (NULL);
	map = temp;
	lst = lst->next;
	while (lst)
	{
		if (!(map->next = ft_lstnew((*f)(lst)->content,
						(*f)(lst)->content_size)))
		{
			ft_lstdel(&temp, ft_lstfree);
			return (NULL);
		}
		lst = lst->next;
		map = map->next;
	}
	return (temp);
}
