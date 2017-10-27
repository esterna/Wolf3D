/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:06:13 by esterna           #+#    #+#             */
/*   Updated: 2017/06/22 16:10:12 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_strdup(const char *src)
{
	char *cp;

	cp = (char *)malloc(ft_strlen((char *)src) + 1);
	if (cp == NULL)
		return (NULL);
	ft_strcpy(cp, (char *)src);
	return (cp);
}
