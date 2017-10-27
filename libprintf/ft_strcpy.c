/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 01:37:20 by esterna           #+#    #+#             */
/*   Updated: 2017/06/22 16:11:16 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char *cpydst;

	cpydst = dest;
	while (*src != 0)
		*cpydst++ = *src++;
	*cpydst = *src;
	return (dest);
}
