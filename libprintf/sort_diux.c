/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_diux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 17:30:32 by esterna           #+#    #+#             */
/*   Updated: 2017/08/29 18:28:34 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*sort_i(t_format format, va_list arg)
{
	long long	i;
	intmax_t	j;

	if (format.length == -2)
		return (ft_itoa_base((signed char)va_arg(arg, int), 10));
	else if (format.length == -1)
		return (ft_itoa_base((short)va_arg(arg, int), 10));
	else if (0 <= format.length && format.length <= 2)
	{
		if (format.length == 1 || format.specifier == 'D')
			i = va_arg(arg, long int);
		else
			i = format.length != 0 ? va_arg(arg, long long) : va_arg(arg, int);
		return (ft_ulltoa_base(((i >= 0) ? i : i * -1),
					((i >= 0) ? 'p' : 'n'), 10));
	}
	else if (format.length == 3)
	{
		j = va_arg(arg, intmax_t);
		return (ft_ulltoa_base(((j >= 0) ? j : j * -1),
					((j >= 0) ? 'p' : 'n'), 10));
	}
	i = va_arg(arg, long long);
	return (ft_ulltoa_base(((i >= 0) ? i : i * -1),
				((i >= 0) ? 'p' : 'n'), 10));
}

char			*sort_x(t_format format, va_list arg)
{
	char	*tmp;
	int		base;

	base = (format.specifier == 'X' || format.specifier == 'x') ? 16 : 8;
	if (format.length == 1)
		tmp = ft_ulltoa_base(va_arg(arg, unsigned long), 'p', base);
	else if (format.length == -2)
		tmp = ft_ulltoa_base(
				(unsigned char)va_arg(arg, unsigned int), 'p', base);
	else if (format.length == -1)
		tmp = ft_ulltoa_base(
				(unsigned short)va_arg(arg, unsigned int), 'p', base);
	else if (format.length == 0)
		tmp = ft_ulltoa_base(va_arg(arg, unsigned int), 'p', base);
	else if (format.length == 2)
		tmp = ft_ulltoa_base(
				va_arg(arg, unsigned long long int), 'p', base);
	else if (format.length == 3)
		tmp = ft_ulltoa_base(va_arg(arg, uintmax_t), 'p', base);
	else if (format.length == 4)
		tmp = ft_ulltoa_base(va_arg(arg, size_t), 'p', base);
	if (65 <= format.specifier && format.specifier <= 90)
		return (ft_str_toupper(tmp));
	return (tmp);
}

char			*sort_u(t_format format, va_list arg)
{
	if (format.length == 1 || format.specifier == 'U')
		return (ft_ulltoa_base(va_arg(arg, unsigned long int), 'p', 10));
	else if (format.length == -2)
		return (ft_ulltoa_base(
					(unsigned char)va_arg(arg, unsigned int), 'p', 10));
	else if (format.length == -1)
		return (ft_ulltoa_base(
					(unsigned short)va_arg(arg, unsigned int), 'p', 10));
	else if (format.length == 0)
		return (ft_ulltoa_base(va_arg(arg, unsigned int), 'p', 10));
	else if (format.length == 2)
		return (ft_ulltoa_base(va_arg(arg, unsigned long long int), 'p', 10));
	else if (format.length == 3)
		return (ft_ulltoa_base(va_arg(arg, uintmax_t), 'p', 10));
	else if (format.length == 4)
		return (ft_ulltoa_base(va_arg(arg, size_t), 'p', 10));
	return (NULL);
}

static char		*sort_g(t_format format, long double dbl, int base)
{
	int		exp;
	int		prec;
	char	*tmp;

	exp = find_exponent(dbl, 10);
	if (format.specifier == 'g' || format.specifier == 'G')
		prec = format.precision == 0 ? 1 : format.precision;
	if (exp < -4 || exp >= prec)
	{
		format.specifier = format.specifier - 2;
		tmp = ft_dtosf_base(dbl, 10, format.precision);
	}
	else
	{
		if ((prec = dbl_frac_size(dbl, 10, format.precision)) > format.precision)
			tmp = ft_dtoa_base(dbl, base, format.precision);
		else
			tmp = ft_dtoa_base(dbl, base, prec);
		format.specifier--;
	}
	return (tmp);
}

char			*sort_d(t_format format, va_list arg)
{
	char		*tmp;
	long double	dbl;
	int			base;

	tmp = NULL;
	dbl = (format.length == 0) ? va_arg(arg, double) : va_arg(arg, long double);
	base = (format.specifier == 'A' || format.specifier == 'a') ? 16 : 10;
	if (format.specifier != 'a' && format.specifier != 'A')
		format.precision = format.precision >= 0 ? format.precision : 6;
	dbl = ft_round_dbl(dbl, format.precision);
	if (format.specifier == 'G' || format.specifier == 'g')
		tmp = sort_g(format, dbl, base);
	else if (format.specifier != 'F' && format.specifier != 'f')
		tmp = ft_dtosf_base(dbl, base, format.precision);
	else
		tmp = ft_dtoa_base(dbl, base, format.precision);
	if (65 <= format.specifier && format.specifier <= 90)
		tmp = ft_str_toupper(tmp);
	return (tmp);
}
