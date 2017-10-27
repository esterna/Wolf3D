/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:08:21 by esterna           #+#    #+#             */
/*   Updated: 2017/08/18 14:28:41 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			nbr_size(unsigned long long n, char sign, int base)
{
	int len;

	len = (sign == 'n' && base == 10) ? 1 : 0;
	if (n == 0)
		len++;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

static char			*str_setup(unsigned long long n, char sign, int base)
{
	int		len;
	char	*nbr;

	len = nbr_size(n, sign, base);
	nbr = ft_strnew(len);
	if (base == 2 && sign == 'n')
	{
		len--;
		while (len >= 0)
			nbr[len--] = '0';
	}
	if (sign == 'n' && base == 10)
		*nbr = '-';
	return (nbr);
}

static char			*invert_binary(char *nbr)
{
	char *tmp;

	tmp = nbr;
	while (*tmp)
	{
		*tmp = (*tmp == '0') ? '1' : '0';
		tmp++;
	}
	return (nbr);
}

/*
** Converts an unsigned long long into a char string using a given base,
** the sign tells whether the original number was negative or positive.
** For binary, negative numbers are represented in "Two's Complement",
** this is done by flipping the bits of the given number and adding 1.
*/

char				*ft_ulltoa_base(unsigned long long n, char sign, int base)
{
	int		len;
	char	*nbr;
	char	*bstr;

	bstr = "0123456789abcdef";
	if (base < 2)
		return (NULL);
	if (sign == 'n' && base == 2)
		n++;
	len = nbr_size(n, sign, base) - 1;
	nbr = str_setup(n, sign, base);
	if (!nbr)
		return (NULL);
	while (len)
	{
		nbr[len--] = bstr[n % base];
		n = n / base;
	}
	if (nbr[len] != '-')
		nbr[len] = bstr[n % base];
	if (sign == 'n' && base == 2)
		nbr = invert_binary(nbr);
	return (nbr);
}
