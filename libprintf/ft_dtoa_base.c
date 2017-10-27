/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 19:27:58 by esterna           #+#    #+#             */
/*   Updated: 2017/08/16 16:02:00 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** This function takes the given double, base,
** and precision and sets up the return string,
** with the NULL character,the '-' if negative,
** and 0x if hexadecimal.
*/

static char			*str_setup(double dbl, int base, int precision)
{
	char			*sf;
	long long		len;

	len = dbl_front_size(dbl, base) + ((precision > 0) ? precision + 1 : 0)
			+ ((dbl < 0) ? 1 : 0) + ((base == 16) ? 2 : 0);
	sf = ft_strnew(sizeof(char) * len);
	if (dbl < 0)
		*sf = '-';
	else if (base == 16)
	{
		*(sf + ((dbl < 0) ? 1 : 0)) = '0';
		*(sf + 1 + ((dbl < 0) ? 1 : 0)) = 'x';
	}
	return (sf);
}

/*
** This function adds the part of the number
** before the decimal to the given string.
*/

static void			part1(char *str, double dbl, int base)
{
	long long	n;
	char		*bstr;

	bstr = "0123456789abcdef";
	n = (long long)dbl;
	if (n > 0)
	{
		while (n)
		{
			*str = bstr[n % base];
			str--;
			n = n / base;
		}
	}
	else
		*str = '0';
}

/*
** This function adds the part of the number
** after the decimal, up to the given precision,
** to the given string.
*/

static char			*part2(char *str, double dbl, int base, int precision)
{
	long long	n;
	int			p;
	double		dtmp;
	char		*bstr;

	bstr = "0123456789abcdef";
	dtmp = dbl - (long long)dbl;
	p = precision;
	while (p-- > 0)
		dtmp *= 10;
	n = (long long)dtmp;
	p = precision;
	while (p > 0)
	{
		*str = bstr[n % base];
		str--;
		p--;
		n = n / base;
	}
	if (precision > 0)
	{
		*str = '.';
		str--;
	}
	return (str);
}

char				*ft_dtoa_base(double dbl, int base, int precision)
{
	char	*sf;
	char	*tmp;

	if (base < 2)
		return (NULL);
	sf = str_setup(dbl, base, precision);
	tmp = sf + dbl_front_size(dbl, base) + ((precision > 0) ? precision + 1 : 0)
			+ ((dbl < 0) ? 1 : 0) + ((base == 16) ? 2 : 0) - 1;
	if (dbl < 0)
		dbl *= -1;
	part1(part2(tmp, dbl, base, precision), dbl, base);
	return (sf);
}
