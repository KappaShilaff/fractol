/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsthead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:00:14 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/24 21:04:39 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lsthead(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (*lst && lst && new)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
