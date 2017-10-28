/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 01:24:57 by esterna           #+#    #+#             */
/*   Updated: 2017/10/27 17:20:03 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "minilibx_macos_10.11/mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libftprintf/libftprintf.h"
# include <math.h>
# include <fcntl.h>
# include <limits.h>

# define WIN_X				1280
# define WIN_Y				1024
# define FOV				M_PI / 4.0
# define DIS_TO_PR			(WIN_X / 2.0) / tan(FOV / 2.0)

typedef struct				s_keys
{
	int			w;
	int			s;
	int			a;
	int			d;
	int			q;
	int			e;
}							t_keys;

typedef struct				s_point
{
	double		x;
	double		y;
	double		z;
}							t_point;

typedef struct				s_frame
{
	void		*mlx;
	void		*window;
	int			*image;
	int			*data;
	int			redraw;
	int			map_x;
	int			map_y;
	int			**map;
	t_point		curr_pos;
	double		view_point;
	t_point		ray;
	t_point		distance;
	double		wall_cons;
	double		dx;
	double		dy;
	t_keys		keys;
}							t_frame;

int							collision(double dx, double dy, t_frame *frame);

void						draw_wall(t_frame *frame, int x, double angle);

void						floor_ceil(t_frame *frame);

int							get_color(t_frame *frame, double angle);

int							key_pressed(int keycode, t_frame *frame);

int							key_released(int keycode, t_frame *frame);

void						ray_caster(t_frame *frame);

void						read_map(t_frame *frame, char *file);

int							start(t_frame *frame);

void						wolf_exit(t_frame *frame, int i);

#endif
