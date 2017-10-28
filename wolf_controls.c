/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:25:24 by esterna           #+#    #+#             */
/*   Updated: 2017/10/27 17:00:11 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					key_pressed(int keycode, t_frame *frame)
{
	if (keycode == 53)
		wolf_exit(frame, 0);
	(keycode == 12) ? frame->keys.q = 1 : 0;
	(keycode == 14) ? frame->keys.e = 1 : 0;
	(keycode == 0) ? frame->keys.a = 1 : 0;
	(keycode == 1) ? frame->keys.s = 1 : 0;
	(keycode == 2) ? frame->keys.d = 1 : 0;
	(keycode == 13) ? frame->keys.w = 1 : 0;
	return (0);
}

int					key_released(int keycode, t_frame *frame)
{
	(keycode == 12) ? frame->keys.q = 0 : 1;
	(keycode == 14) ? frame->keys.e = 0 : 1;
	(keycode == 0) ? frame->keys.a = 0 : 1;
	(keycode == 1) ? frame->keys.s = 0 : 1;
	(keycode == 2) ? frame->keys.d = 0 : 1;
	(keycode == 13) ? frame->keys.w = 0 : 1;
	return (0);
}
