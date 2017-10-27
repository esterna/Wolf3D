/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 17:19:59 by esterna           #+#    #+#             */
/*   Updated: 2017/07/25 17:31:04 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** This function rounds dbl to the nearest integer, but rounds
** halfway cases away from 0.
** For example, round(0.5) is 1.0, and round(-0.5) is -1.0.
** If x is integral, +0, -0, NaN, or infinite, x itself is returned.
*/

double				ft_round(double dbl)
{
	return ((dbl >= 0) ? (long)(dbl + 0.5) : (long)(dbl - 0.5));
}
