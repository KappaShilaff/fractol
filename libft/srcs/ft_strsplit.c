/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:32:58 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/24 21:50:29 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**len_free(char **split)
{
	while (*split++)
		free(*(split - 1));
	free(split);
	return (NULL);
}

static size_t	get_len(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 1;
	while (s[i])
	{
		if (s[i] != c)
		{
			len++;
			while (s[i] != c && s[i])
				i++;
			i--;
		}
		i++;
	}
	return (len);
}

static size_t	get_len_word(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 1;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	k;
	size_t	j;

	k = 0;
	if (!s || !c || !(split = malloc(sizeof(char *) * get_len(s, c))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			if (!(split[k] = (char *)malloc(sizeof(char) * get_len_word(s, c))))
				return (len_free(split));
			j = 0;
			while (*s != c && *s)
				split[k][j++] = *s++;
			split[k][j] = '\0';
			k++;
			s--;
		}
		s++;
	}
	split[k] = NULL;
	return (split);
}
