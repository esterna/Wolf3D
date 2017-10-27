/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 19:16:48 by esterna           #+#    #+#             */
/*   Updated: 2017/06/01 22:53:29 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			nbr_size(int n, int base)
{
	int len;

	len = 1;
	if (n <= 0)
	{
		n = n * -1;
		len++;
	}
	while (n)
	{
		n = n / base;
		len++;
	}
	return (len);
}

static char			*str_setup(int n, int base)
{
	int		len;
	char	*nbr;

	len = nbr_size(n, base);
	nbr = (char *)malloc(sizeof(char) * len);
	if (!nbr)
		return (NULL);
	nbr[--len] = '\0';
	if (n < 0)
		*nbr = '-';
	return (nbr);
}

char				*ft_itoa_base(int n, int base)
{
	int		neg;
	int		len;
	char	*nbr;
	char	*bstr;

	neg = 1;
	bstr = "0123456789ABCDEF";
	if (base < 2)
		return (NULL);
	len = nbr_size(n, base) - 2;
	nbr = str_setup(n, base);
	if (!nbr)
		return (NULL);
	if (n < 0)
		neg = -1;
	while (len)
	{
		nbr[len--] = bstr[neg * (n % base)];
		n = n / base;
	}
	if (nbr[len] != '-')
		nbr[len] = bstr[neg * (n % base)];
	return (nbr);
}
