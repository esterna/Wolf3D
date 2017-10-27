/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:15:25 by esterna           #+#    #+#             */
/*   Updated: 2017/08/22 22:39:10 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int n;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		i = 0;
		n = 0;
		while (haystack[n] == needle[i] &&
				needle[i] != '\0' && haystack[n] != '\0')
		{
			n++;
			i++;
		}
		if (needle[i] == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
