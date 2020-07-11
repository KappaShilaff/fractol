/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chround.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 21:30:53 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/28 01:44:59 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		*zeronum(size_t n)
{
	char	*res;
	size_t	i;

	i = 0;
	n += 2;
	res = ft_chmalloc_zend(n);
	while (i < n)
		res[i++] = '0';
	res[1] = '.';
	res[n - 1] = '1';
	return (res);
}

static void		norme1(int i[1], int k[1], int n[1], char **str)
{
	char	*buf;

	i[0] = 0;
	k[0] = 0;
	while ((*str)[i[0]] && (*str)[i[0]] != '.')
		i[0]++;
	if (i[0] + n[0] + 1 < (int)ft_strlen(*str))
		if ((*str)[i[0] + n[0] + 1] >= '5' && (*str)[i[0] + n[0] + 1] <= '9')
		{
			buf = zeronum(n[0]);
			*str = ft_chsum(*str, buf);
			free(buf);
			k[0] = 1;
		}
}

static char		*norme2(char **str, int i, int k, char *buf)
{
	char	*buf2;

	while ((*str)[i] == '0')
		i++;
	if ((*str)[i] == '.')
	{
		if ((*str)[i + 1] && (*str)[i + 1] >= '5' && (*str)[i + 1] <= '9')
			buf = ft_strdup("1");
		else
			buf = ft_strdup("0");
	}
	else
	{
		while ((*str)[i + k] != '.')
			k++;
		buf = ft_chmalloc_zend(k);
		if ((*str)[i + k + 1] && (*str)[i + k + 1] >= '5' &&
		(*str)[i + k + 1] <= '9')
			buf2 = ft_chsum(*str, "1.0");
		else
			buf2 = ft_strdup(*str);
		ft_strncpy(buf, buf2, k);
		free(buf2);
	}
	return (buf);
}

char			*ft_chround(char *str, int n)
{
	char	*res;
	int		i;
	int		size;
	int		k;

	if (n == 0)
		return (norme2(&str, 0, 0, NULL));
	norme1(&i, &k, &n, &str);
	res = ft_chmalloc_zend(i + n + 1);
	size = i + n;
	i = 0;
	while ((size-- >= 0) && str[i])
	{
		res[i] = str[i];
		i++;
	}
	while (size-- >= -1)
		res[i++] = '0';
	if (k == 1)
		free(str);
	return (res);
}
