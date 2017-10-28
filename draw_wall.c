/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:44:15 by esterna           #+#    #+#             */
/*   Updated: 2017/10/27 17:18:14 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

int				get_color(t_frame *frame, double angle)
{
	int		we;

	we = 0;
	while (angle < 0.0 || angle > 2.0 * M_PI)
		angle = angle + (angle < 0.0 ? 2.0 * M_PI : -2.0 * M_PI);
	angle = ft_round_dbl(angle, 1);
	if (frame->distance.x <= frame->distance.y)
		we = 1;
	if (M_PI / 2.0 < angle && angle <= 3.0 * M_PI / 2.0 && we == 1)
		return (0xD10D81);
	if (((0.0 <= angle && angle <= M_PI / 2.0) ||
		(3.0 * M_PI / 2.0 < angle && angle <= 2.0 * M_PI)) && we == 1)
		return (0xFF6400);
	if (M_PI / 2.0 < angle && angle <= 3.0 * M_PI / 2.0 > 0 && we == 0)
		return (0xB40505);
	if (((0.0 <= angle && angle <= M_PI / 2.0) ||
		(3.0 * M_PI / 2.0 < angle && angle <= 2.0 * M_PI)) && we == 0)
		return (0xFFDC00);
	return (0xFFFFFF);
}

void			draw_wall(t_frame *frame, int x, double angle)
{
	double		wall_h;
	int			y0;
	int			i;
	int			color;

	i = 0;
	wall_h = ceil((64.0 / (frame->distance.y <= frame->distance.x ?
					frame->distance.y : frame->distance.x)) * DIS_TO_PR);
	wall_h = (wall_h >= WIN_Y) ? WIN_Y : wall_h;
	y0 = (WIN_Y - wall_h) / 2.0;
	y0 = y0 < 0.0 ? 0.0 : y0;
	color = get_color(frame, angle);
	while (wall_h > 0.0)
	{
		frame->data[x + y0 * WIN_X + i * WIN_X] = color;
		i++;
		wall_h--;
	}
}
