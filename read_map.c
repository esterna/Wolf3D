/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:49:03 by esterna           #+#    #+#             */
/*   Updated: 2017/10/27 20:00:51 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			set_curr_pos(t_frame *frame, int x, int y)
{
	frame->curr_pos.y = (64.0 * (double)(y)) + 32.0;
	frame->curr_pos.x = (64.0 * (double)(x)) + 32.0;
	frame->map[y][x] = 0;
}

static void		utility(t_frame *frame, int y, int fd, char *line)
{
	int		x;

	x = 0;
	while (*line != '\0')
	{
		if (*line == 'X')
			set_curr_pos(frame, x, y);
		else
		{
			if (!('0' <= *line && *line <= '9'))
			{
				close(fd);
				wolf_exit(frame, -2);
			}
			frame->map[y][x] = *line - '0';
		}
		line++;
		x++;
	}
}

void			fill_map(t_frame *frame, char *file)
{
	char		*line;
	int			fd;
	int			y;

	if ((fd = open(file, O_RDONLY)) < 1)
		wolf_exit(frame, -1);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		utility(frame, y, fd, line);
		y++;
		ft_strdel(&line);
	}
	close(fd);
}

void			read_map(t_frame *frame, char *file)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 1)
		wolf_exit(frame, -1);
	get_next_line(fd, &line);
	frame->map_x = ft_strlen(line);
	frame->map_y = 1;
	ft_strdel(&line);
	while (get_next_line(fd, &line) > 0)
	{
		frame->map_y++;
		if ((int)ft_strlen(line) != frame->map_x)
			wolf_exit(frame, -1);
		ft_strdel(&line);
	}
	close(fd);
	frame->map = ft_2dintnew(frame->map_y, frame->map_x);
	fill_map(frame, file);
	if (frame->curr_pos.x == -1.0 || frame->curr_pos.y == -1.0)
		wolf_exit(frame, -2);
}
