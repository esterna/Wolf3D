/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:25:24 by esterna           #+#    #+#             */
/*   Updated: 2017/10/25 18:55:00 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					key_pressed(int keycode, t_frame *frame)
{
	if (keycode == 53)
		wolf_exit(frame, 0);
	(keycode == 12) ? frame->keys.q = 1 : 0;//turn left
	(keycode == 14) ? frame->keys.e = 1 : 0;//turn right
	(keycode == 0) ? frame->keys.a = 1 : 0; //move left
	(keycode == 1) ? frame->keys.s = 1 : 0; //move backwards
	(keycode == 2) ? frame->keys.d = 1 : 0; //move right
	(keycode == 13) ? frame->keys.w = 1 : 0; //move forwards
	return (0);
}

int					key_released(int keycode, t_frame *frame)
{
	(keycode == 12) ? frame->keys.q = 0 : 1;//turn left
	(keycode == 14) ? frame->keys.e = 0 : 1;//turn right
	(keycode == 0) ? frame->keys.a = 0 : 1; //move left
	(keycode == 1) ? frame->keys.s = 0 : 1; //move backwards
	(keycode == 2) ? frame->keys.d = 0 : 1; //move right
	(keycode == 13) ? frame->keys.w = 0 : 1; //move forwards
	return (0);
}
