/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 22:29:28 by esterna           #+#    #+#             */
/*   Updated: 2017/10/19 20:26:01 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				*ft_intnew(int size)
{
	int		*new;
	int		i;

	i = 0;
	new = (int *)malloc(sizeof(int) * size);
	if (new == NULL)
		return (NULL);
	while (i < size)
	{
		new[i] = 0;
		i++;
	}
	return (new);
}
