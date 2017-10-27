/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 01:23:02 by esterna           #+#    #+#             */
/*   Updated: 2017/10/26 15:27:41 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			wolf_exit(t_frame *frame, int i)
{
	if (i == 3)
	{
		free(frame);
		printf("usage: ./wolf3d map_name\n");
		exit(0);
	}
	if (i == -1)
	{
		free(frame);
		printf("Error: Invalid Map File\n");
		exit(0);
	}
	ft_free_array((void **)frame->map, frame->map_y);
	mlx_destroy_image(frame->mlx, frame->image);
	mlx_destroy_window(frame->mlx, frame->window);
	free(frame);
	system("killall afplay");
	exit(0);
}

void			frame_init(t_frame *frame)
{
	int		bpp;
	int		size_line;
	int		endian;

	frame->redraw = 1;
	frame->view_point = M_PI / 4.0;
	frame->dis_to_pr = (WIN_X / 2.0) / tan(30.0 * (M_PI / 180.0));
	frame->mlx = mlx_init();
	frame->window = mlx_new_window(frame->mlx, WIN_X, WIN_Y, "Wolf3D");
	frame->image = (int *)mlx_new_image(frame->mlx, WIN_X, WIN_Y);
	frame->data = (int *)mlx_get_data_addr(frame->image,
			&bpp, &size_line, &endian);
	frame->keys.w = 0;
	frame->keys.a = 0;
	frame->keys.s = 0;
	frame->keys.d = 0;
	frame->keys.q = 0;
	frame->keys.e = 0;
}

int				exit_hook(t_frame *frame)
{
	wolf_exit(frame, 0);
	return (0);
}

int				main(int argc, char **argv)
{
	t_frame		*frame;

	frame = (t_frame *)malloc(sizeof(t_frame));
	if (argc != 2)
		wolf_exit(frame, 3);
	read_map(frame, *(argv + 1));
	frame_init(frame);
//	system("afplay Electric_Daisy_Lindsey_Stirling.mp3 &");
	mlx_hook(frame->window, 2, 0, key_pressed, frame);
	mlx_hook(frame->window, 3, 0, key_released, frame);
	mlx_hook(frame->window, 17, 0, exit_hook, frame);
	mlx_loop_hook(frame->mlx, start, frame);
	mlx_loop(frame->mlx);
//	ray_caster(frame);
	return (0);
}
