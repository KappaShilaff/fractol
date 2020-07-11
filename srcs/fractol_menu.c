/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:24:29 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/08 18:14:47 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		fr_hidemenu_fill(t_fr **fr)
{
	fr[0]->img = mlx_new_image(fr[0]->mlx, WIDTH - fr[0]->menu, HEIGHT);
	fr[0]->img_str = mlx_get_data_addr(fr[0]->img, &fr[0]->bpp,
			&fr[0]->strlen, &fr[0]->endian);
	fr[1]->img_str = fr[0]->img_str;
	fr[2]->img_str = fr[0]->img_str;
	fr[3]->img_str = fr[0]->img_str;
	fr[1]->img = fr[0]->img;
	fr[2]->img = fr[0]->img;
	fr[3]->img = fr[0]->img;
}

void		fr_hidemenu(int key, t_fr **fr)
{
	if (key == KEY_F)
	{
		if (fr[0]->menu == 340)
		{
			fr[0]->menu = 0;
			fr[1]->menu = 0;
			fr[2]->menu = 0;
			fr[3]->menu = 0;
		}
		else
		{
			fr[0]->menu = 340;
			fr[1]->menu = 340;
			fr[2]->menu = 340;
			fr[3]->menu = 340;
		}
		mlx_destroy_image(fr[0]->mlx, fr[0]->img);
		mlx_clear_window(fr[0]->mlx, fr[0]->win);
		fr_draw_menu(fr);
		fr_hidemenu_fill(fr);
		fr_draw(fr);
	}
}

void		fr_draw_menu(t_fr **fr)
{
	if (fr[0]->menu == 340)
	{
		mlx_string_put(fr[0]->mlx, fr[0]->win,
			WIDTH - 330, 30, 0xffffff, "Julia        - 1");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
			WIDTH - 330, 60, 0xffffff, "Burning ship - 2");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
			WIDTH - 330, 90, 0xffffff, "Chameleon    - 3");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
			WIDTH - 330, 120, 0xffffff, "Mandelbrot   - 4");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
			WIDTH - 330, 150, 0xffffff, "Move         - w a s d");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
			WIDTH - 330, 180, 0xffffff, "Zoom         - mouse scroll");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
			WIDTH - 330, 210, 0xffffff, "       or left/right button");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
			WIDTH - 330, 240, 0xffffff, "Color change - q");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
			WIDTH - 330, 270, 0xffffff, "Hide menu    - f");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
			WIDTH - 330, 300, 0xffffff, "Exit         - esc");
		mlx_string_put(fr[0]->mlx, fr[0]->win,
			WIDTH - 330, 390, 0xffffff, "Julia/Chameleon mouse hook - e");
	}
}
