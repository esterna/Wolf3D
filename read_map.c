/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:49:03 by esterna           #+#    #+#             */
/*   Updated: 2017/10/25 22:44:11 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			fill_map(t_frame *frame, char *file)
{
	char		*line;
	char		*tmp;
	int			fd;
	int			x;
	int			y;

	if ((fd = open(file, O_RDONLY)) < 1)
		wolf_exit(frame, -1);
	frame->map = ft_2dintnew(frame->map_y, frame->map_x);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		tmp = line;
		while (*tmp != '\0')
		{
			if (*tmp == 'X')
			{
				frame->curr_pos[0] = (64.0 * (double)(y - 1)) + 32.0;
				frame->curr_pos[1] = (64.0 * (double)(x - 1)) + 32.0;
				frame->map[y][x] = 0;
				tmp++;
				x++;
			}
			if (!('0' <= *tmp && *tmp <= '9'))
			{
				ft_free_array((void **)frame->map, frame->map_y);
				wolf_exit(frame, -1);
			}
			frame->map[y][x] = *tmp - '0';
			tmp++;
			x++;
		}
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
	fill_map(frame, file);
}
