/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hookmove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:00:57 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/08 18:09:17 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fr_move_switch(int key, t_fr **fr)
{
	if (key == KEY_E)
	{
		if (fr[0]->hook_move == 1)
		{
			fr[0]->hook_move = 0;
			fr[1]->hook_move = 0;
			fr[2]->hook_move = 0;
			fr[3]->hook_move = 0;
		}
		else
		{
			fr[0]->hook_move = 1;
			fr[1]->hook_move = 1;
			fr[2]->hook_move = 1;
			fr[3]->hook_move = 1;
		}
	}
}

void	fr_hook_move_area1(int x, int y, t_fr **fr)
{
	if (x < WIDTH / 2 && y < WIDTH / 2)
	{
		fr[0]->c_r += 0.005;
		fr[1]->c_r += 0.005;
		fr[2]->c_r += 0.005;
		fr[3]->c_r += 0.005;
	}
	if (x > WIDTH / 2 && y < WIDTH / 2)
	{
		fr[0]->c_r -= 0.005;
		fr[1]->c_r -= 0.005;
		fr[2]->c_r -= 0.005;
		fr[3]->c_r -= 0.005;
	}
}

void	fr_hook_move_area2(int x, int y, t_fr **fr)
{
	if (x < WIDTH / 2 && y > WIDTH / 2)
	{
		fr[0]->c_i += 0.005;
		fr[1]->c_i += 0.005;
		fr[2]->c_i += 0.005;
		fr[3]->c_i += 0.005;
	}
	if (x > WIDTH / 2 && y > WIDTH / 2)
	{
		fr[0]->c_i -= 0.005;
		fr[1]->c_i -= 0.005;
		fr[2]->c_i -= 0.005;
		fr[3]->c_i -= 0.005;
	}
}

int		fr_hook_move_mouse(int x, int y, t_fr **fr)
{
	if (fr[0]->fr_switch == 1 || fr[0]->fr_switch == 3)
	{
		if (fr[0]->hook_move == 1)
		{
			if (x < WIDTH && y < HEIGHT)
			{
				fr_hook_move_area1(x, y, fr);
				fr_hook_move_area2(x, y, fr);
			}
			fr_draw(fr);
		}
	}
	return (0);
}
