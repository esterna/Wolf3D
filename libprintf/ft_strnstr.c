/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:30:58 by esterna           #+#    #+#             */
/*   Updated: 2017/08/22 22:39:10 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int n;
	int tmp_len;

	if (*needle == '\0')
		return ((char *)haystack);
	while (len > 0 && *haystack)
	{
		i = 0;
		n = 0;
		tmp_len = len;
		while (haystack[n] == needle[i] && needle[i] && haystack[n] && tmp_len)
		{
			tmp_len--;
			n++;
			i++;
		}
		if (needle[i] == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
