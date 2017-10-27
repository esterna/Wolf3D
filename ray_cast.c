/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:52:13 by esterna           #+#    #+#             */
/*   Updated: 2017/10/26 21:41:26 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					collision_ray(t_frame *frame)
{
	int		x;
	int		y;

	y = (int)floor(frame->ray[0] / 64.0);
	x = (int)floor(frame->ray[1] / 64.0);
	if (!(0 < y && y < frame->map_y && 0 < x && x < frame->map_x))
		return (0);
	return (1);
}

void			floor_ceil(t_frame *frame)
{
	int		y;
	int		x;
	int		color;

	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		color = (y < WIN_Y / 2) ? 0x75DBFF : 0x461185;
		while (x < WIN_X)
		{
			frame->data[x + y * WIN_X] = color;
			x++;
		}
		y++;
	}
}

int				get_color(t_frame *frame)
{
	int		we;

	we = 0;
	if (frame->distance[0] <= frame->distance[1])
		we = 1;
	if (M_PI / 2.0 <= frame->view_point && frame->view_point <= 3.0 * M_PI / 2.0 && we == 1)
		return (0xD10D81);
	if (((0.0 < frame->view_point && frame->view_point <= M_PI / 2.0) ||
		(3.0 * M_PI / 2.0 < frame->view_point && frame->view_point <= 2.0 * M_PI))
		   	&& we == 1)
		return (0xFF6400);
	if (M_PI / 2.0 <= frame->view_point && frame->view_point <= 3.0 * M_PI / 2.0 && we == 0)
		return (0xB40505);
	if (((0.0 < frame->view_point && frame->view_point <= M_PI / 2.0) ||
		(3.0 * M_PI / 2.0 < frame->view_point && frame->view_point <= 2.0 * M_PI)) && we == 0)
		return (0xFFDC00);
	return (0xFFFFFF);
}

void			draw_wall(t_frame *frame, int x)
{	
	double		wall_h;
	int			y0;
	int			i;
	int			color;

	i = 0;
	//	ft_printf("frame->ray[1] : %f\tangle : %f\tdistance to wall: %f\n", angle, frame->ray[1], frame->distance);
	wall_h = ceil((64.0 / (frame->distance[0] <= frame->distance[1] ? frame->distance[0] : frame->distance[1])) * frame->dis_to_pr);
	wall_h = (wall_h >= WIN_Y) ? WIN_Y : wall_h;
	y0 = (WIN_Y - wall_h) / 2.0;
	y0 = y0 < 0.0 ? 0.0 : y0;
	color = get_color(frame);
	while (wall_h > 0.0)
	{
		frame->data[x + y0 * WIN_X + i * WIN_X] = color;
		i++;
		wall_h--;
	}
}

void			x_dir_ray(t_frame *frame, double angle)
{
	frame->ray[0] = ((frame->curr_pos[0] / 64.0) * 64.0) + ((angle >= M_PI) ? 64.0 : -1.0);
	frame->ray[1] = frame->curr_pos[1] + ((frame->curr_pos[0] - frame->ray[0]) / tan(angle));
	frame->dy = (angle > M_PI) ? 64.0 : -64.0;
	frame->dx = (64.0 / tan(angle)) * ((angle > M_PI) ? -1.0 : 1.0);
	while (collision_ray(frame) == 1 &&
			frame->map[(int)floor(frame->ray[0] / 64.0)][(int)floor(frame->ray[1] / 64.0)] == 0)
	{
		frame->ray[0] += frame->dy;
		frame->ray[1] += frame->dx;
	}
	frame->distance[0] = fabs((frame->curr_pos[0] - frame->ray[0]) / sin(angle)) * cos(frame->view_point - angle);
	frame->distance[0] = (frame->distance[0] < 0) ? INT_MAX : frame->distance[0];
}

void			y_dir_ray(t_frame *frame, double angle)
{
	frame->ray[1] = ((frame->curr_pos[0] / 64.0) * 64.0) + ((angle > M_PI / 2.0 && angle < 3.0 * M_PI / 2.0) ? -1.0 : 64.0);
	frame->ray[0] = frame->curr_pos[0] + ((frame->curr_pos[1] - frame->ray[1]) * tan(angle));
	frame->dx = (angle > M_PI / 2.0 && angle < 3.0 * M_PI / 2.0) ? -64.0 : 64.0;
	frame->dy = (64.0 * tan(angle)) * ((angle > M_PI / 2.0 && angle < 3.0 * M_PI / 2.0) ? 1.0 : -1.0);
	while (collision_ray(frame) == 1 &&
			frame->map[(int)floor(frame->ray[0] / 64.0)][(int)floor(frame->ray[1] / 64.0)] == 0)
	{
		frame->ray[0] += frame->dy;
		frame->ray[1] += frame->dx;
	}
	frame->distance[1] = fabs((frame->curr_pos[1] - frame->ray[1]) / cos(angle)) * cos(frame->view_point - angle);	
	frame->distance[1] = (frame->distance[1] < 0) ? INT_MAX : frame->distance[1];
}

void			ray_caster(t_frame *frame)
{
	int			i;
	double		angle;
	double		rot_ang;

	if (frame->redraw == 0)
		return ;
	frame->redraw = 0;
//	ft_printf("%f, %f\n", frame->curr_pos[1], frame->curr_pos[0]);
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
	//	ft_printf("angle : %f\tdx : %f\tdy : %f\tray_x : %f\tray_y : %f\n", angle, frame->dx, frame->dy, frame->ray[1], frame->ray[0]);
		draw_wall(frame, i);
		angle -= rot_ang;
		i++;
	}
	mlx_put_image_to_window(frame->mlx, frame->window, frame->image, 0, 0);
}
