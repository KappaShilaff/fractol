/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:29:29 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/20 17:45:27 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*newstr;
	size_t		i;
	size_t		j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i != j)
		i++;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j != i)
		j--;
	if (i == j)
		return ("\0");
	newstr = ft_strsub(s, i, (j - i + 1));
	if (!newstr)
		return (NULL);
	return (newstr);
}
