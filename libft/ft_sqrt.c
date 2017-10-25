/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 15:57:49 by esterna           #+#    #+#             */
/*   Updated: 2017/09/05 18:44:36 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double		test(double x, double y)
{
	if (ft_abs_dbl((x / y) - y) < 0.000000001)
		return (y);
	else
		return (test(x, (y + (x / y)) / 2.0));
}

double				ft_sqrt(double n)
{
	return (test(n, 1.0));
}
