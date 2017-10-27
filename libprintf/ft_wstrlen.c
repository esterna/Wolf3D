/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 18:16:21 by esterna           #+#    #+#             */
/*   Updated: 2017/08/04 21:08:12 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t				ft_wstrlen(const wchar_t *str)
{
	size_t n;

	n = 0;
	while (*str)
	{
		if (*str <= 127)
			n++;
		else if (*str <= 2047)
			n += 2;
		else if (*str <= 65535)
			n += 3;
		else
			n += 4;
		str++;
	}
	return (n);
}
