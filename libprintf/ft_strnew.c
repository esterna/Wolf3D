/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:20:07 by esterna           #+#    #+#             */
/*   Updated: 2017/06/13 16:01:24 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (size + 1));
	if (tmp == NULL)
		return (NULL);
	while (i <= size)
	{
		tmp[i] = '\0';
		i++;
	}
	return (tmp);
}
