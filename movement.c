/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:58:23 by esterna           #+#    #+#             */
/*   Updated: 2017/10/27 19:51:10 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					collision(double dx, double dy, t_frame *frame)
{
	int		x;
	int		y;
	double	pos_x;
	double	pos_y;

	pos_y = frame->curr_pos.y;
	pos_x = frame->curr_pos.x;
	pos_y += dy;
	pos_x += dx;
	y = (int)(pos_y / 64.0);
	x = (int)(pos_x / 64.0);
	if (!(0 <= y && y < frame->map_y && 0 <= x &&
				x < frame->map_x) || frame->map[y][x] != 0)
		return (0);
	frame->curr_pos.y += dy;
	frame->curr_pos.x += dx;
	return (1);
}

void				up_down(t_frame *frame)
{
	t_keys		k_tmp;
	double		dx;
	double		dy;

	k_tmp = frame->keys;
	if (k_tmp.w == 1 || k_tmp.s == 1)
	{
		dx = cos(frame->view_point) * 10.0;
		dy = sin(frame->view_point) * 10.0;
		if (k_tmp.w == 1 && collision(dx, -1.0 * dy, frame) == 1)
		{
			frame->curr_pos.x += dx;
			frame->curr_pos.y -= dy;
		}
		if (k_tmp.s == 1 && collision(-1.0 * dx, dy, frame) == 1)
		{
			frame->curr_pos.x -= dx;
			frame->curr_pos.y += dy;
		}
		frame->redraw = 1;
	}
}

void				left_right(t_frame *frame)
{
	t_keys		k_tmp;
	double		dx;
	double		dy;

	k_tmp = frame->keys;
	if (k_tmp.a == 1 || k_tmp.d == 1)
	{
		dx = cos(frame->view_point - (M_PI / 2.0)) * 10.0;
		dy = sin(frame->view_point - (M_PI / 2.0)) * 10.0;
		if (k_tmp.a == 1 && collision(-1.0 * dx, dy, frame) == 1)
		{
			frame->curr_pos.x -= dx;
			frame->curr_pos.y += dy;
		}
		if (k_tmp.d == 1 && collision(dx, -1.0 * dy, frame) == 1)
		{
			frame->curr_pos.x += dx;
			frame->curr_pos.y -= dy;
		}
		frame->redraw = 1;
	}
}

int					start(void *fr_tmp)
{
	t_keys		k_tmp;
	t_frame		*frame;
	
	frame = (t_frame *)fr_tmp;
	k_tmp = frame->keys;
	if (k_tmp.w == 1 || k_tmp.s == 1)
		up_down(frame);
	if (k_tmp.a == 1 || k_tmp.d == 1)
		left_right(frame);
	if (k_tmp.q == 1 || k_tmp.e == 1)
	{
		frame->view_point += (M_PI / 128.0) * (k_tmp.e == 1 ? -1.0 : 1.0);
		while (frame->view_point < 0.0 || frame->view_point >= 2.0 * M_PI)
			frame->view_point += (2.0 * M_PI) *\
				(frame->view_point < 0.0 ? 1.0 : -1.0);
		frame->redraw = 1;
	}
	ray_caster(frame);
	return (0);
}
