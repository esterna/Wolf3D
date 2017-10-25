/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:31:21 by esterna           #+#    #+#             */
/*   Updated: 2017/10/20 20:27:49 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			ft_fmod(double nb, double div)
{
	double	ret;
	int		sign;

	sign = nb < 0 ? -1 : 1;
	if (div == 0 || nb * sign > 8e22 || div > 8e22 || div < -8e22)
		return (1e60);
	ret = nb - (div * (long)(nb / div));
	if (ret * sign < 0)
		ret *= -1;
	return (ret);
}
