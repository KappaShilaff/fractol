/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_create_mlx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:57:48 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/08 18:34:38 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fr_fill_another(t_fr **fr)
{
	fr[1]->win = fr[0]->win;
	fr[1]->img = fr[0]->img;
	fr[1]->mlx = fr[0]->mlx;
	fr[1]->img_str = fr[0]->img_str;
	fr[1]->menu = fr[0]->menu;
	fr[2]->mlx = fr[0]->mlx;
	fr[2]->win = fr[0]->win;
	fr[2]->img = fr[0]->img;
	fr[2]->img_str = fr[0]->img_str;
	fr[2]->menu = fr[0]->menu;
	fr[3]->mlx = fr[0]->mlx;
	fr[3]->win = fr[0]->win;
	fr[3]->img = fr[0]->img;
	fr[3]->img_str = fr[0]->img_str;
	fr[3]->menu = fr[0]->menu;
}

void	fr_create_mlx(t_fr **fr)
{
	fr[0]->mlx = mlx_init();
	fr[0]->win = mlx_new_window(fr[0]->mlx, WIDTH, HEIGHT, "Fractol");
	fr[0]->img = mlx_new_image(fr[0]->mlx, WIDTH - fr[0]->menu, HEIGHT);
	fr[0]->img_str = mlx_get_data_addr(fr[0]->img,
			&fr[0]->bpp, &fr[0]->strlen, &fr[0]->endian);
	mlx_mouse_hook(fr[0]->win, fr_mouse, fr);
	mlx_key_hook(fr[0]->win, fr_key, fr);
	mlx_hook(fr[0]->win, 6, 0, fr_hook_move_mouse, fr);
	fr_draw_menu(fr);
	fr[0]->shift_y = 0;
	fr[0]->shift_x = 0;
	fr_fill_another(fr);
}
