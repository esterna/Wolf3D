/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:04:44 by esterna           #+#    #+#             */
/*   Updated: 2017/06/06 14:09:19 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchr(const char *str, int c)
{
	char *tmp;

	tmp = (char *)str;
	while (*tmp != (char)c && *tmp != '\0')
		tmp++;
	if (*tmp == (char)c)
		return (tmp);
	return (0);
}
