/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 01:24:57 by esterna           #+#    #+#             */
/*   Updated: 2017/10/24 03:52:52 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "minilibx_macos_10.11/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>

# define WIN_X				1280
# define WIN_Y				1024

typedef struct				s_frame
{
	void		*mlx;
	void		*window;
	int			*image;
	int			*data;
	int			redraw;
	double		curr_pos[2];
	double		view_point[2];
	double		ray[2];
	double		distance;
	double		dis_to_pr;
	double		wall_cons;
	double		dx;
	double		dy;
//	int			map[24][24];
}							t_frame;



#endif
