/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exponent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 12:41:15 by esterna           #+#    #+#             */
/*   Updated: 2017/06/21 12:44:16 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** This function takes a double and
** converts it to scientific notation using
** the given base and precision.
*/

int		find_exponent(double dbl, int base)
{
	int exp;
	int div;

	exp = 0;
	div = (base == 10) ? 10 : 2;
	if (dbl < 0)
		dbl = dbl * -1;
	while (dbl >= div)
	{
		dbl = dbl / div;
		exp++;
	}
	while (0 < dbl && dbl < 1)
	{
		dbl = dbl * div;
		exp--;
	}
	return (exp);
}
