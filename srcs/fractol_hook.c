/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mouse_hook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:25:47 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/08 20:40:46 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		fr_key_shift(int key, t_fr *fr)
{
	if (key == KEY_W)
	{
		fr->shift_y = -100 / fr->zoom;
		fr->shift_x = 0;
	}
	if (key == KEY_S)
	{
		fr->shift_y = 100 / fr->zoom;
		fr->shift_x = 0;
	}
	if (key == KEY_A)
	{
		fr->shift_x = -100 / fr->zoom;
		fr->shift_y = 0;
	}
	if (key == KEY_D)
	{
		fr->shift_x = 100 / fr->zoom;
		fr->shift_y = 0;
	}
	fr->x1 += fr->shift_x;
	fr->y1 += fr->shift_y;
}

int				fr_mouse(int code, int x, int y, t_fr **fr)
{
	if (code == 4 || code == 1)
	{
		fr_zoom(fr[0], x, y);
		fr_zoom(fr[1], x, y);
		fr_zoom(fr[2], x, y);
		fr_zoom(fr[3], x, y);
		fr_draw(fr);
	}
	else if (code == 5 || code == 2)
	{
		fr_dezoom(fr[0], x, y);
		fr_dezoom(fr[1], x, y);
		fr_dezoom(fr[2], x, y);
		fr_dezoom(fr[3], x, y);
		fr_draw(fr);
	}
	return (0);
}

void			fr_key_switch(int key, t_fr **fr)
{
	if (key == KEY_1)
		fr_julia(fr);
	if (key == KEY_2)
		fr_ship(fr);
	if (key == KEY_3)
		fr_chameleon(fr);
	if (key == KEY_4)
		fr_mandelbrot(fr);
}

int				fr_key(int key, t_fr **fr)
{
	fr_key_switch(key, fr);
	fr_color_switch(key, fr);
	if (key == KEY_ESC)
	{
		free(fr[0]->thread_id);
		free(fr[0]);
		free(fr[1]);
		free(fr[2]);
		free(fr[3]);
		free(fr);
		exit(EXIT_SUCCESS);
	}
	if ((key >= 0 && key <= 2) || key == 13)
	{
		fr_key_shift(key, fr[0]);
		fr_key_shift(key, fr[1]);
		fr_key_shift(key, fr[2]);
		fr_key_shift(key, fr[3]);
		fr_draw(fr);
	}
	fr_move_switch(key, fr);
	fr_hidemenu(key, fr);
	return (0);
}
