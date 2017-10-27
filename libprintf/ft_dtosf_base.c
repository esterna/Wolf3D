/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtosf_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 13:47:49 by esterna           #+#    #+#             */
/*   Updated: 2017/09/05 20:57:05 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** This function finds the resulting double
** after dividing by the base (10 or 2)
** to the power of the result of find_exponent.
*/

static double		find_starting_point(double dbl, int base)
{
	int		exp;
	double	div;
	double	b;

	b = (base == 10) ? 10.0 : 2.0;
	div = 1.0;
	exp = find_exponent(dbl, base);
	while (exp > 0)
	{
		div = div * b;
		exp--;
	}
	while (exp < 0)
	{
		div = div / b;
		exp++;
	}
	return (dbl / div);
}

int					find_precision(double dbl, int base)
{
	double	start;
	int		n;

	n = 0;
	start = find_starting_point(dbl, base);
	start = (start < 0) ? start * -1 : start;
	start = start - (long)start;
	while (0 < start && start < 1)
	{
		start *= base;
		n++;
		start = start - (long)start;
	}
	return (n);
}

/*
** This function takes the given double, base,
** and precision and sets up the return string,
** with the NULL character, the exponent and exponent
** sign, e or p, the '-' if negative, and
** 0x if hexadecimal.
*/

static char			*str_setup(double dbl, int base, int precision)
{
	char	*sf;
	int		exp;
	int		len;

	exp = find_exponent(dbl, base);
	len = 2 + ((precision > 0) ? precision + 1 : 0) + 
		((base == 16) ? 2 : 0) + ft_nbrsize_base(exp, base);
	sf = ft_strnew(sizeof(char) * len);
	*sf = (dbl < 0.0) ? '-' : '\0';
	if (base == 10 && precision != 0)
		*(sf + ((dbl < 0.0) ? 2 : 1)) = '.';
	else if (base == 16)
	{
		*(sf + ((dbl < 0.0) ? 1 : 0)) = '0';
		*(sf + 1 + ((dbl < 0.0) ? 1 : 0)) = 'x';
		if (precision != 0)
			*(sf + 3 + ((dbl < 0.0) ? 1 : 0)) = '.';
	}
	len--;
	sf[len--] = (((exp < 0) ? exp * -1 : exp) % 10) + '0';
	if ((exp = ft_abs(exp)) > 9 || base == 10)
	{
		sf[len--] = ((exp /= 10) == 0) ? '0' : (exp % 10) + '0'; 
		while ((exp /= 10) > 0)
			sf[len--] = exp % 10 + '0';
	}
	sf[len--] = (find_exponent(dbl, base) >= 0) ? '+' : '-';
	sf[len--] = (base == 10) ? 'e' : 'p';
	return (sf);
}

static char			*nan_inf(double dbl)
{
	if (dbl == INFINITY)
		return (ft_strdup("inf"));
	else if (dbl == -INFINITY)
		return (ft_strdup("-inf"));
	else if (dbl == NAN)
		return (ft_strdup("nan"));
	return (ft_strdup("-nan"));
}

char				*ft_dtosf_base(double dbl, int base, int precision)
{
	char	*sf;
	char	*bstr;
	char	*tmp;

	bstr = "0123456789abcdef";
	if (base < 2)
		return (NULL);
	if (dbl == INFINITY || dbl == -INFINITY || dbl == NAN || dbl == -NAN)
		return (nan_inf(dbl));
	dbl = ft_round_dbl(dbl, ft_abs(find_exponent(dbl, base)) + precision);
	precision = (precision >= 0) ? precision : find_precision(dbl, base);
	sf = str_setup(dbl, base, precision);
	tmp = sf + ((dbl < 0) ? 1 : 0) + ((base == 16) ? 2 : 0);
	if (dbl < 0)
		dbl = dbl * -1.0;
	dbl = find_starting_point(dbl, base);
	dbl = (base == 10) ? ft_round_dbl(dbl, precision) : dbl;
	*tmp = bstr[(long)((precision == 0) ? ft_round_dbl(dbl, 0.0) : dbl)];
	tmp = tmp + ((precision != 0) ? 2 : 1);
	while (*tmp != 'e' && *tmp != 'p')
	{
		dbl = ft_fmod(dbl, 1.0) * base;
		*tmp = bstr[(long)(*(tmp + 1) == 'e' ? ft_round_dbl(dbl, 0.0) : dbl)];
		tmp++;
	}
	return (sf);
}
