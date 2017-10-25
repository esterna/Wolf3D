/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:44:21 by esterna           #+#    #+#             */
/*   Updated: 2017/03/08 21:47:46 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int			nbr_size(int n)
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
		n = n / 10;
		len++;
	}
	return (len);
}

static char			*str_setup(int n)
{
	int		len;
	char	*nbr;

	len = nbr_size(n);
	nbr = (char *)malloc(sizeof(char) * len);
	if (!nbr)
		return (NULL);
	nbr[--len] = '\0';
	if (n < 0)
		*nbr = '-';
	return (nbr);
}

char				*ft_itoa(int n)
{
	int		neg;
	int		len;
	char	*nbr;

	neg = 0;
	len = nbr_size(n) - 2;
	nbr = str_setup(n);
	if (n < 0)
	{
		neg = 1;
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		n = n * -1;
	}
	if (!nbr)
		return (NULL);
	while (len)
	{
		nbr[len--] = n % 10 + '0';
		n = n / 10;
	}
	if (nbr[len] != '-')
		nbr[len] = n % 10 + '0';
	return (nbr);
}
