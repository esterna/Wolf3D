/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 19:35:11 by esterna           #+#    #+#             */
/*   Updated: 2017/10/22 18:35:36 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		base_e(char *nbr)
{
	long long	p;
	double		result;

	result = 1.0;
	if (*nbr != 'e' && *nbr != 'E')
		return (1.0);
	nbr++;
	p = ft_atoi(nbr);
	if (p == 0)
		return (1.0);
	while (p > 0)
	{
		result *= 10.0;
		p--;
	}
	while (p < 0)
	{
		result /= 10.0;
		p++;
	}
	return (result);
}

double		ft_atod(char *nbr)
{
	int		neg;
	int		power;
	double	result;

	neg = 1;
	power = 1;
	result = 0;
	if (!nbr)
		return (0);
	while (ft_isspace(*nbr) != 0)
		nbr++;
	if (*nbr == '-' || *nbr == '+')
	{
		neg = (*nbr == '-') ? -1 : 1;
		nbr++;
	}
	while (ft_isdigit(*nbr) != 0)
	{
		result = result * 10 + (*nbr - '0');
		nbr++;
	}
	if (*nbr == '.')
		nbr++;
	while (ft_isdigit(*nbr) != 0)
	{
		result = result * 10 + (*nbr - '0');
		nbr++;
		power *= 10.0;
	}
	result = (neg * result / power) * base_e(nbr);
	return (result);
}
