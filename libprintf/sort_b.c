/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 22:14:54 by esterna           #+#    #+#             */
/*   Updated: 2017/08/17 22:14:55 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*sort_b(t_format format, va_list arg)
{
	long long	i;
	intmax_t	j;

	if (format.length == -2)
		return (ft_itoa_base((signed char)va_arg(arg, int), 2));
	else if (format.length == -1)
		return (ft_itoa_base((short)va_arg(arg, int), 2));
	else if (0 <= format.length && format.length <= 2)
	{
		if (format.length == 1 || format.specifier == 'D')
			i = va_arg(arg, long int);
		else
			i = format.length != 0 ? va_arg(arg, long long) : va_arg(arg, int);
		return (ft_ulltoa_base(((i >= 0) ? i : i * -1),
					((i >= 0) ? 'p' : 'n'), 2));
	}
	else if (format.length == 3)
	{
		j = va_arg(arg, intmax_t);
		return (ft_ulltoa_base(((j >= 0) ? j : j * -1),
					((j >= 0) ? 'p' : 'n'), 2));
	}
	i = va_arg(arg, long long);
	return (ft_ulltoa_base(((i >= 0) ? i : i * -1),
				((i >= 0) ? 'p' : 'n'), 2));
}
