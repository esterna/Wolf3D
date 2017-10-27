/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 20:48:32 by esterna           #+#    #+#             */
/*   Updated: 2017/09/05 16:28:11 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** This function finds the size of the part of the number
** before the decimal point.
*/

int			dbl_front_size(double dbl, int base)
{
	int n;

	n = 1;
	if (dbl < 0)
		dbl *= -1;
	dbl = (long long)dbl;
	while ((long long)dbl > 9)
	{
		dbl /= base;
		n++;
	}
	return (n);
}

int			dbl_frac_size(double dbl, int base, int precision)
{
	int n;

	n = 0;
	if (dbl < 0)
		dbl *= -1;
	dbl = (dbl - (long long)dbl) * base;
	while (((long long) dbl) == 0 && n < 12)
	{
		dbl *= base;
		n++;
	}
	if ((long long) dbl == 0)
		return (0);
	while (dbl >= 0.1 && n <= precision + 1)
	{
		dbl = (dbl - (long long)dbl) * base;
		n++;
	}
	return (n);
}
