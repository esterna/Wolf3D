/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:40:11 by esterna           #+#    #+#             */
/*   Updated: 2017/03/21 16:58:42 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;

	tmp_d = (unsigned char *)dest;
	tmp_s = (unsigned char *)src;
	if (tmp_s < tmp_d && tmp_s + (n - 1) >= tmp_d)
	{
		tmp_s = tmp_s + (n - 1);
		tmp_d = tmp_d + (n - 1);
		while (n)
		{
			*tmp_d-- = *tmp_s--;
			n--;
		}
	}
	else
	{
		while (n)
		{
			*tmp_d++ = *tmp_s++;
			n--;
		}
	}
	return (dest);
}
