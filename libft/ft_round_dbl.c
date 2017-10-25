/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_dbl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 14:22:13 by esterna           #+#    #+#             */
/*   Updated: 2017/10/20 20:30:10 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function takes a double and rounds to a certain number
** of places after the decimal point, given by the precision.
*/

double			ft_round_dbl(double dbl, int precision)
{
	long		n;
	long		p;
	double		tmp;
	double		fac;
	double		result;

	tmp = (dbl >= 0) ? dbl : dbl * -1;
	fac = ft_pow(10, precision + 1);
	precision = (precision <= 0) ? 0 : precision;
	p = precision + 1;
	n = (precision == 0) ? ((long)dbl) % 10 : 0;
	while (p)
	{
		tmp = (tmp - (long)tmp) * 10;
		n = (p == 1) ? (long)tmp : n;
		p--;
	}
	result = 5 / fac;
	if (n < 5)
		return (dbl);
	if (dbl < 0)
		return (dbl - result);
	return (dbl + result);
}
