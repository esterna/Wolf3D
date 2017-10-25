/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 21:58:42 by esterna           #+#    #+#             */
/*   Updated: 2017/10/20 20:28:58 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double					ft_pow(double base, double exp)
{
	if (base == 1.0 || exp == 0.0)
		return (1.0);
	else if (exp < 0.0)
		return (1.0 / ft_pow(base, exp * -1.0));
	return (base * ft_pow(base, exp - 1.0));
}
