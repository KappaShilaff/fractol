/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:50:19 by lcassaun          #+#    #+#             */
/*   Updated: 2020/07/08 18:34:38 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	fr_fill_mandel(t_fr *fr, int i)
{
	fr->x = 0;
	fr->y = 0;
	fr->i = 0;
	fr->x1 = -5.5;
	fr->y1 = -3.25;
	fr->itmax = 40;
	fr->zoom = 150;
	fr->fr_switch = 2;
	fr->thread = i;
	fr->rgb1 = 100;
	fr->rgb2 = 100;
}

static void	fr_calc_mandel(t_fr *fr)
{
	while (fr->z_r * fr->z_r + fr->z_i * fr->z_i < 4 && fr->i < fr->itmax)
	{
		fr->tmp = fr->z_r;
		fr->z_r = fr->z_r * fr->z_r - fr->z_i * fr->z_i + fr->c_r;
		fr->z_i = 2 * fr->z_i * fr->tmp + fr->c_i;
		fr->i++;
	}
}

void		fr_mandelbrot_draw_thread(t_fr *fr)
{
	fr->y += fr->thread;
	while (fr->y < HEIGHT)
	{
		while (fr->x < WIDTH - fr->menu)
		{
			fr->c_r = fr->x / fr->zoom + fr->x1;
			fr->c_i = fr->y / fr->zoom + fr->y1;
			fr->z_r = 0;
			fr->z_i = 0;
			fr_calc_mandel(fr);
			fr_bfr_pix(fr);
			fr->i = 0;
			fr->x++;
		}
		fr->y += 4;
		fr->x = 0;
	}
	fr->x = 0;
	fr->y = 0;
	pthread_exit(0);
}

void		fr_mandelbrot_draw(t_fr **fr)
{
	pthread_create(&(fr[0]->thread_id[0]), NULL,
			(void *)fr_mandelbrot_draw_thread, fr[0]);
	pthread_create(&(fr[0]->thread_id[1]), NULL,
			(void *)fr_mandelbrot_draw_thread, fr[1]);
	pthread_create(&(fr[0]->thread_id[2]), NULL,
			(void *)fr_mandelbrot_draw_thread, fr[2]);
	pthread_create(&(fr[0]->thread_id[3]), NULL,
			(void *)fr_mandelbrot_draw_thread, fr[3]);
	pthread_join(fr[0]->thread_id[0], NULL);
	pthread_join(fr[0]->thread_id[1], NULL);
	pthread_join(fr[0]->thread_id[2], NULL);
	pthread_join(fr[0]->thread_id[3], NULL);
	mlx_put_image_to_window(fr[0]->mlx, fr[0]->win, fr[0]->img, 0, 0);
	mlx_loop(fr[0]->mlx);
}

void		fr_mandelbrot(t_fr **fr)
{
	fr_fill_mandel(fr[0], 0);
	fr_fill_mandel(fr[1], 1);
	fr_fill_mandel(fr[2], 2);
	fr_fill_mandel(fr[3], 3);
	fr_mandelbrot_draw(fr);
}
