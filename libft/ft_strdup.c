/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:06:13 by esterna           #+#    #+#             */
/*   Updated: 2017/03/03 19:48:37 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strdup(const char *src)
{
	char *cp;

	cp = (char *)malloc(ft_strlen((char *)src) + 1);
	if (cp == NULL)
		return (NULL);
	ft_strcpy(cp, (char *)src);
	return (cp);
}
