/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 16:48:07 by esterna           #+#    #+#             */
/*   Updated: 2017/08/22 21:08:59 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_putwchar_fd(wchar_t ch, int fd)
{
	if (ch < (MB_CUR_MAX == 1 ? 255 : 127))
		ft_putchar_fd(ch, fd);
	else if (ch <= 2047)
	{
		ft_putchar_fd(192 | ((ch >> 6) & 31), fd);
		ft_putchar_fd(128 | (ch & 63), fd);
	}
	else if (ch <= 65535)
	{
		ft_putchar_fd(224 | ((ch >> 12) & 15), fd);
		ft_putchar_fd(128 | ((ch >> 6) & 63), fd);
		ft_putchar_fd(128 | (ch & 63), fd);
	}
	else
	{
		ft_putchar_fd(240 | ((ch >> 18) & 7), fd);
		ft_putchar_fd(128 | ((ch >> 12) & 63), fd);
		ft_putchar_fd(128 | ((ch >> 6) & 63), fd);
		ft_putchar_fd(128 | (ch & 63), fd);
	}
}
