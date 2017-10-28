/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:52:13 by esterna           #+#    #+#             */
/*   Updated: 2017/10/27 17:30:36 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					collision_ray(t_frame *frame)
{
	int		x;
	int		y;

	y = (int)(frame->ray.y / 64.0);
	x = (int)(frame->ray.x / 64.0);
	if (!(0 < y && y < frame->map_y && 0 < x && x < frame->map_x))
		return (0);
	return (1);
}

void				x_dir_ray(t_frame *frame, double angle)
{
	int		x;
	int		y;

	frame->ray.y = (floor(frame->curr_pos.y / 64.0) * 64.0)
					+ ((angle >= M_PI) ? 64.0 : -1.0);
	frame->ray.x = frame->curr_pos.x +
					((frame->curr_pos.y - frame->ray.y) / tan(angle));
	frame->dy = (angle > M_PI) ? 64.0 : -64.0;
	frame->dx = (64.0 / tan(angle)) * ((angle > M_PI) ? -1.0 : 1.0);
	x = (int)(frame->ray.x / 64.0);
	y = (int)(frame->ray.y / 64.0);
	while (collision_ray(frame) == 1 && frame->map[y][x] == 0)
	{
		frame->ray.y += frame->dy;
		frame->ray.x += frame->dx;
		x = (int)(frame->ray.x / 64.0);
		y = (int)(frame->ray.y / 64.0);
	}
	frame->distance.x = fabs((frame->curr_pos.y - frame->ray.y) /
						sin(angle)) * cos(frame->view_point - angle);
	frame->distance.x = (frame->distance.x < 0) ? INT_MAX : frame->distance.x;
}

void				y_dir_ray(t_frame *frame, double angle)
{
	int		x;
	int		y;

	frame->ray.x = (floor(frame->curr_pos.x / 64.0) * 64.0) +
				((angle > M_PI / 2.0 && angle < 3.0 * M_PI / 2.0)
						? -1.0 : 64.0);
	frame->ray.y = frame->curr_pos.y +
				((frame->curr_pos.x - frame->ray.x) * tan(angle));
	frame->dx = (angle > M_PI / 2.0 && angle < 3.0 * M_PI / 2.0) ? -64.0 : 64.0;
	frame->dy = (64.0 * tan(angle)) *
				((angle > M_PI / 2.0 && angle < 3.0 * M_PI / 2.0) ? 1.0 : -1.0);
	x = (int)(frame->ray.x / 64.0);
	y = (int)(frame->ray.y / 64.0);
	while (collision_ray(frame) == 1 && frame->map[y][x] == 0)
	{
		frame->ray.y += frame->dy;
		frame->ray.x += frame->dx;
		x = (int)(frame->ray.x / 64.0);
		y = (int)(frame->ray.y / 64.0);
	}
	frame->distance.y = fabs((frame->curr_pos.x - frame->ray.x) /
						cos(angle)) * cos(frame->view_point - angle);
	frame->distance.y = (frame->distance.y < 0) ? INT_MAX : frame->distance.y;
}

void				ray_caster(t_frame *frame)
{
	int			i;
	double		angle;
	double		rot_ang;

	if (frame->redraw == 0)
		return ;
	frame->redraw = 0;
	floor_ceil(frame);
	i = 0;
	angle = frame->view_point + FOV;
	while (angle > 2.0 * M_PI)
		angle -= (2.0 * M_PI);
	rot_ang = FOV / (double)WIN_X;
	while (i < WIN_X)
	{
		while (angle < 0)
			angle += (2.0 * M_PI);
		x_dir_ray(frame, angle);
		y_dir_ray(frame, angle);
		draw_wall(frame, i, angle);
		angle -= rot_ang;
		i++;
	}
	mlx_put_image_to_window(frame->mlx, frame->window, frame->image, 0, 0);
}
