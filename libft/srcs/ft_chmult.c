/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chmult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 01:54:06 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/28 01:55:18 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		norme1(char *str1, char *str2, int i[5])
{
	while (str1[i[1]] && str1[i[1]] != '.')
		i[1]++;
	while (str2[i[2]] && str2[i[2]] != '.')
		i[2]++;
	while (str1[i[1] + i[3]])
		i[3]++;
	while (str2[i[2] + i[4]])
		i[4]++;
	i[0] = i[1] + i[2] + i[3] + i[4] - 1;
	i[5] = i[3] + i[4] - 1;
}

static void		norme2(int i[9])
{
	i[1] += i[3] - 1;
	i[2] += i[4] - 1;
	i[0]--;
	i[6] = i[0];
	i[7] = i[1];
	i[8] = i[0];
}

static void		norme3(char *res, char *str1, char *str2, int i[10])
{
	while (i[2] >= 0)
	{
		i[0] = i[6];
		if (res[i[0]] == 100)
			i[9] = i[0]-- + i[6]--;
		if (str2[i[2]] == '.')
			i[2]--;
		i[1] = i[7];
		while (i[1] >= 0)
		{
			if (str1[i[1]] == '.')
				i[1]--;
			i[9] = (str1[i[1]] - '0') * (str2[i[2]] - '0') + res[i[0]];
			res[i[0]] = i[9] % 10;
			if (res[--i[0]] == 100)
				i[0]--;
			res[i[0]] += i[9] / 10;
			i[1]--;
		}
		i[9] = i[6]-- + i[2]--;
	}
}

static void		norme4(int i[10], char **res)
{
	char	*del;

	if ((*res)[0] == '0' && (*res)[1] != '.')
	{
		del = *res;
		*res = ft_strdup(*res + 1);
		free(del);
		i[8]--;
	}
	while ((*res)[i[8]] == '0' && (*res)[i[8] - 1] != '.')
		(*res)[i[8]--] = '\0';
}

char			*ft_chmult(char *str1, char *str2)
{
	int		i[10];
	char	*res;

	ft_bzero(i, sizeof(int[10]));
	norme1(str1, str2, i);
	res = ft_memalloc(i[0] + 3);
	res[i[0] - i[5]] = 100;
	norme2(i);
	norme3(res, str1, str2, i);
	i[0] = 0;
	while (res[i[0]] == '\0')
		res[i[0]++] = '0';
	while (i[0] <= i[8])
	{
		if (res[i[0]] == 100)
			res[i[0]++] = '.';
		res[i[0]++] += '0';
	}
	norme4(i, &res);
	return (res);
}
