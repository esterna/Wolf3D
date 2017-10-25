/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:37:04 by esterna           #+#    #+#             */
/*   Updated: 2017/10/20 20:33:54 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_modf(double x, double *integer)
{
	*integer = (int)x;
	return (ft_fmod(x, 1.0));
}
