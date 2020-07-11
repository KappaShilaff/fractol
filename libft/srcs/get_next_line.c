/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:38:44 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/25 23:05:43 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			gnl_fill(t_cont *t, long int buff)
{
	t->len += t->tmp;
	t->tmp = 0;
	t->temp = t->str;
	t->str = ft_chmalloc_zend(buff);
	t->rm = t->str;
	return (0);
}

int			gfree(t_cont *t, long int i)
{
	if (t->temp != NULL)
	{
		t->str = ft_strjoin(t->temp, t->str - i);
		ft_free_enull(&(t->temp));
		ft_free_enull(&(t->rm));
	}
	else
		t->str = t->str - i;
	return (1);
}

long int	gnl_n(t_cont *t, long int buff)
{
	long int		i[3];

	while ((i[0] = gnl_fill(t, buff)) == 0)
	{
		i[2] = buff;
		while (i[2] != 0)
		{
			if ((i[1] = read(t->fd, t->str, BUFF_SIZE)) == 0)
			{
				if (i[2] == buff && (t->str = ft_strdup(t->temp) +
							ft_free_enull(&(t->temp))))
					return (-2);
				return (-1 * gfree(t, i[0]));
			}
			t->tmp += i[1];
			t->str[i[1]] = '\0';
			while (*t->str != '\0')
				if (++i[0] && (*(t->str)++ == '\n') && (gfree(t, i[0])))
					return (t->len + i[0] - 1);
			i[2] -= i[1];
		}
		buff *= 2 * gfree(t, i[0]);
	}
	return (0);
}

char		*gnl_str(t_cont *t, int i)
{
	if (t->str && (i = ft_findchr(t->str, '\n')) >= 0)
	{
		t->join = ft_memstrncpy(NULL, t->str, i++);
		t->temp = t->str;
		t->str = ft_strdup(t->str + i);
		t->len -= i - ft_free_enull(&(t->temp));
		return (t->join);
	}
	if ((i = gnl_n(t, BUFF_SIZE)) == -1)
	{
		t->join = ft_strdup(t->str);
		return (t->join + ft_free_enull(&(t->str)));
	}
	if (i == -2)
	{
		if (t->len != 0 && (t->join = ft_memstrncpy(NULL, t->str, t->len)))
			return (t->join + ft_free_enull(&(t->str)));
		return (NULL);
	}
	t->join = ft_memstrncpy(NULL, t->str, i++);
	t->temp = t->str;
	t->str = ft_strdup(t->str + i);
	t->len -= i;
	ft_free_enull(&(t->temp));
	return (t->join);
}

int			get_next_line(const int fd, char **line)
{
	static t_node	*root[590432];
	int				i;

	i = 0;
	if (fd < 0 || !line || read(fd, 0, 0) < 0)
		return (-1);
	if (!root[fd])
	{
		root[fd] = ft_create_node(ft_create_cont_fd(fd));
		i = 1;
	}
	if (i == 0 && (((t_cont *)(root[fd]->d))->str == NULL))
		return (0);
	if ((*line = ft_strdup(gnl_str(((t_cont *)(root[fd]->d)), 0))) != NULL)
	{
		ft_free_enull(&((((t_cont *)(root[fd]->d))->join)));
		return (1);
	}
	free(((t_cont *)(root[fd]->d))->rm);
	return (0);
}
