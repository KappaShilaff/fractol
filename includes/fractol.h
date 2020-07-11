/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:09:39 by bzmuda            #+#    #+#             */
/*   Updated: 2020/07/08 18:34:38 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../srcs/libft/includes/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <pthread.h>
# define WIDTH			1800
# define HEIGHT 		900
# define KEY_ESC		53
# define KEY_W 			13
# define KEY_S 			1
# define KEY_A 			0
# define KEY_D 			2
# define KEY_F 			3
# define KEY_E 			14
# define KEY_1 			18
# define KEY_2 			19
# define KEY_3 			20
# define KEY_4 			21
# define KEY_Q 			12

typedef struct		s_fr
{
	char			*argv;
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_str;
	int				endian;
	int				strlen;
	int				bpp;
	int				fr_switch;
	int				x;
	int				y;
	int				i;
	int				color;
	int				s_l;
	double			z_r;
	double			z_i;
	double			tmp;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			c_r;
	double			c_i;
	int				itmax;
	double			zoom;
	double			pr;
	double			pi;
	double			shift_x;
	double			shift_y;
	pthread_t		*thread_id;
	int				thread;
	int				menu;
	int				hook_move;
	int				color_index;
	float			rgb1;
	float			rgb2;
	int				color_temp;
	float			color_temp1;
}					t_fr;

void				fr_create_mlx(t_fr **fr);
void				fr_mandelbrot(t_fr **fr);
void				fr_bfr_pix(t_fr *fr);
void				fr_mandelbrot_draw(t_fr **fr);
void				fr_draw(t_fr **fr);
void				fr_zoom(t_fr *fr, int x, int y);
void				fr_dezoom(t_fr *fr, int x, int y);
int					fr_mouse(int code, int x, int y, t_fr **fr);
int					fr_key(int code, t_fr **fr);
void				fr_fill_another(t_fr **fr);
void				fr_chameleon(t_fr **fr);
void				fr_chameleon_draw(t_fr **fr);
void				fr_ship(t_fr **fr);
void				fr_ship_draw(t_fr **fr);
void				fr_julia(t_fr **fr);
void				fr_julia_draw(t_fr **fr);
void				fr_draw_menu(t_fr **fr);
int					fr_hook_move_mouse(int x, int y, t_fr **fr);
void				fr_color(t_fr *fr);
void				fr_move_switch(int key, t_fr **fr);
void				fr_hidemenu(int key, t_fr **fr);
void				fr_color_switch(int key, t_fr **fr);

#endif
