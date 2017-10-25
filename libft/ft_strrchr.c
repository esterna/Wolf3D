/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:09:39 by esterna           #+#    #+#             */
/*   Updated: 2017/03/03 19:29:46 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *tmp;

	tmp = (char *)str;
	while (*tmp != '\0')
		tmp++;
	while (*tmp != (char)c && tmp != str)
		tmp--;
	if (*tmp == (char)c)
		return (tmp);
	return (0);
}
