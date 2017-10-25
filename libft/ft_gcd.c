/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 23:32:57 by esterna           #+#    #+#             */
/*   Updated: 2017/10/22 18:33:47 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Finds the GCD (Greatest Common Divisor)
** or HCF (Highest Common Factor) of two numbers.
*/

int					ft_gcd(int a, int b)
{
	if (a == 0 || b == 0)
		return (0);
	if ((a == 1 || b == 1) || (a > 0 && b < 0)
			|| (a < 0 && b > 0))
		return (1);
	if (a == b)
		return (a);
	if (a > b)
		return (ft_gcd(a - b, b));
	return (ft_gcd(a, b - a));
}
