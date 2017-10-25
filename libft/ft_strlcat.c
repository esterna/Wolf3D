/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 09:51:27 by esterna           #+#    #+#             */
/*   Updated: 2017/03/21 17:03:03 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	int				i;
	int				n;
	size_t			dlen;
	size_t			slen;

	i = 0;
	dlen = (size_t)ft_strlen(dest);
	slen = (size_t)ft_strlen(src);
	n = size - dlen - 1;
	if (dlen >= size)
		return (slen + (size == dlen ? dlen : size));
	while (*dest != '\0')
		dest++;
	while (*src != '\0' && i < n)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (dlen + slen);
}
