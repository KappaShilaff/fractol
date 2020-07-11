/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:53:51 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/08 17:56:08 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fr_color_switch(int key, t_fr **fr)
{
	if (key == KEY_Q)
	{
		fr[0]->color_index = (fr[0]->color_index + 1) % 5;
		fr[1]->color_index = (fr[1]->color_index + 1) % 5;
		fr[2]->color_index = (fr[2]->color_index + 1) % 5;
		fr[3]->color_index = (fr[3]->color_index + 1) % 5;
		fr_draw(fr);
	}
}

void	fr_color(t_fr *fr)
{
	if (fr->color_index == 0)
		fr->color_temp = fr->i * 1100000;
	if (fr->color_index == 1)
	{
		fr->color_temp = (int)((float)fr->i / (float)fr->itmax * 30);
		fr->color_temp = fr->color_temp * fr->color_temp * fr->color_temp;
	}
	if (fr->color_index == 2)
		fr->color_temp = 0xbfffff - 0x000100 * (0xff * fr->i / fr->itmax)
				- 0x000001 * (0xff * fr->i / fr->itmax);
	if (fr->color_index == 3)
		fr->color_temp = 0xffbfff - 0x010000 * (0xff * fr->i / fr->itmax)
				- 0x000001 * (0xff * fr->i / fr->itmax);
	if (fr->color_index == 4)
		fr->color_temp = 0xffffbf - 0x000100 * (0xff * fr->i / fr->itmax)
				- 0x010000 * (0xff * fr->i / fr->itmax);
}
