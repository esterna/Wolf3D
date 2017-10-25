/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:57:55 by esterna           #+#    #+#             */
/*   Updated: 2017/03/03 17:57:42 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*tmp;

	i = 0;
	tmp = (void *)malloc(size);
	if (tmp == NULL)
		return (NULL);
	while (i < size)
	{
		((char *)tmp)[i] = 0;
		i++;
	}
	return (tmp);
}
