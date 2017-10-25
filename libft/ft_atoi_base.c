/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:37:52 by esterna           #+#    #+#             */
/*   Updated: 2017/10/22 18:33:22 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char			*set_base(int b)
{
	const char		*base;

	base = "0123456789abcdef";
	return (ft_strsub(base, 0, b));
}

static int					ind(int n, const char *base)
{
	int				i;

	i = 0;
	while (base[i] && base[i] != n)
		i++;
	return (i);
}

size_t						ft_atoi_base(const char *n, int b)
{
	long long		result;
	long long		neg;
	long long		len;
	const char		*base;

	result = 0;
	base = set_base(b);
	len = ft_strlen((char *)base);
	if (len < 2)
		return (0);
	while (*n == '\t' || *n == '\n' || *n == '\v' || *n == '\f' || *n == '\r'
					|| *n == ' ')
		n++;
	neg = *n == '-';
	if (*n == '+' || *n == '-')
		n++;
	while (*n && ind(*n, base) < len)
	{
		result = result * len + ind(*n, base);
		n++;
	}
	return (neg ? -result : result);
}
