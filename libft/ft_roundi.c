/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:11:27 by esterna           #+#    #+#             */
/*   Updated: 2017/05/18 20:19:19 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Given two integers, where a is to be divided by b,
** if the result of a % b is greater than half
** of b then round up, otherwise round down.
*/

int			ft_roundi(int a, int b)
{
	if (a % b >= 0.5 * (float)b)
		return (a / b + 1);
	return (a / b);
}
