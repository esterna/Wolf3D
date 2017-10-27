/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:58:23 by esterna           #+#    #+#             */
/*   Updated: 2017/10/26 21:47:53 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					collision(double dx, double dy, t_frame *frame)
{
	int		x;
	int		y;

	frame->curr_pos[0] += dy;
	frame->curr_pos[1] += dx;
	y = (int)ceil(frame->curr_pos[0] / 64.0);
	x = (int)ceil(frame->curr_pos[1] / 64.0);
	//ft_printf("%d, %d\t map_size = %d, %d\t z-value : %d\n", x, y, frame->map_x, frame->map_y, frame->map[y][x]);
	if (!(0 <= y && y < frame->map_y && 0 <= x && x < frame->map_x) || frame->map[y][x] != 0)
		return (0);
	return (1);
}

int					start(t_frame *frame)
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
			frame->curr_pos[1] += dx;
			frame->curr_pos[0] -= dy;
		}
		if (k_tmp.s == 1 && collision(-1.0 * dx, dy, frame) == 1)
		{
			frame->curr_pos[1] -= dx;
			frame->curr_pos[0] += dy;
		}
		frame->redraw = 1;
	//	ft_printf("dx = %f, dy = %f\n", dx, dy);
	}
	if (k_tmp.a == 1 || k_tmp.d == 1)
	{
		dx = cos(frame->view_point- (M_PI / 2.0)) * 10.0;
		dy = sin(frame->view_point - (M_PI / 2.0)) * 10.0;
		if (k_tmp.a == 1 && collision(-1.0 * dx, dy, frame) == 1)
		{
			frame->curr_pos[1] -= dx;
			frame->curr_pos[0] += dy;
		}
		if (k_tmp.d == 1 && collision(dx, -1.0 * dy, frame) == 1)
		{
			frame->curr_pos[1] += dx;
			frame->curr_pos[0] -= dy;
		}
		frame->redraw = 1;
	//	ft_printf("dx = %f, dy = %f\n", dx, dy);
	}
	if (k_tmp.q == 1 || k_tmp.e == 1)
	{
		frame->view_point += (M_PI / 128.0) * (k_tmp.e == 1 ? -1.0 : 1.0);
		while (frame->view_point < 0.0 || frame->view_point >= 2.0 * M_PI)
			frame->view_point += (2.0 * M_PI) * (frame->view_point < 0.0 ? 1.0 : -1.0);
		frame->redraw = 1;
	//	ft_printf("frame->view_point = %f\n", frame->view_point);
	}
	ray_caster(frame);
	return (0);
}
