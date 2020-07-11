/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 01:46:42 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/28 01:49:33 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		norme1(char *str1, char *str2, int i[5])
{
	while (str1[i[1]] && str1[i[1]] != '.')
		i[1]++;
	while (str2[i[2]] && str2[i[2]] != '.')
		i[2]++;
	if (i[1] > i[2])
		i[0] = i[1];
	else
		i[0] = i[2];
	while (str1[i[1] + i[3]])
		i[3]++;
	while (str2[i[2] + i[4]])
		i[4]++;
	if (i[3] > i[4])
		i[0] += i[3];
	else
		i[0] += i[4];
	i[3]--;
	i[4]--;
}

static void		norme2(char *str1, char *str2, char *res, int i[5])
{
	while (i[0] > 0)
	{
		if (i[3] == 0)
		{
			if (res[i[0]] != 0)
				res[i[0] - 1] = res[i[0]];
			res[i[0]--] = '.';
			i[3]--;
			i[4]--;
		}
		else
		{
			res[i[0]] += '0';
			if (i[1] + i[3] > -1)
				res[i[0]] += str1[i[1] + i[3]--] - '0';
			if (i[2] + i[4] > -1)
				res[i[0]] += str2[i[2] + i[4]--] - '0';
			if (res[i[0]] - '0' > 9)
			{
				res[i[0] - 1] += (res[i[0]] - '0') / 10;
				res[i[0]] = (res[i[0]] - '0') % 10 + '0';
			}
			i[0]--;
		}
	}
}

static void		norme3(char **res, int i[5])
{
	char	*del;

	if ((*res)[0] == '0' && (*res)[1] != '.')
	{
		del = *res;
		*res = ft_strdup(*res + 1);
		free(del);
	}
	i[0] = (int)ft_strlen(*res) - 1;
	while ((*res)[i[0]] == '0' && ((*res)[i[0] - 1] != '.'))
		(*res)[i[0]--] = '\0';
}

char			*ft_chsum(char *str1, char *str2)
{
	int		i[5];
	char	*res;

	ft_bzero(i, sizeof(int[5]));
	norme1(str1, str2, i);
	res = ft_memalloc(i[0] + 3);
	res[0] = '0';
	if (i[3] > i[4])
		while (i[3] > i[4])
			res[i[0]--] = str1[i[1] + i[3]--];
	else
		while (i[4] > i[3])
			res[i[0]--] = str2[i[2] + i[4]--];
	norme2(str1, str2, res, i);
	norme3(&res, i);
	return (res);
}
