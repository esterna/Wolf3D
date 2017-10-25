/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:57:41 by esterna           #+#    #+#             */
/*   Updated: 2017/10/22 18:34:04 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Frees every item in an array and the array pointer itself,
** on the condition that the array is a malloced one.
** The parameter n is the number of memory blocks in the array.
*/

void		ft_free_array(void **lst, size_t n)
{
	size_t	i;
	int		**tmp;

	i = 0;
	tmp = (int **)lst;
	while (i < n)
	{
		free(tmp[i]);
		i++;
	}
	free(lst);
}
