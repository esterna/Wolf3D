/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:57:29 by esterna           #+#    #+#             */
/*   Updated: 2017/05/18 20:19:47 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Prints out an int 2d array,
**	the parameter n is for how many ints
** there are in a given memory block.
** The last memory block must be NULL.
*/

void			ft_put_int_array(int **array, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (array[i])
	{
		while (j < n)
		{
			ft_putnbr(array[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
	ft_putstr("NULL\n");
}
