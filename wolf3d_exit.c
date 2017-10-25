/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 01:29:12 by esterna           #+#    #+#             */
/*   Updated: 2017/10/24 01:29:47 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				fractol_exit(t_frame *frame)
{
	free(frame);
	mlx_destroy_image(frame->mlx, frame->image);
	mlx_destroy_window(frame->mlx, frame->window);
	exit(0);
}
