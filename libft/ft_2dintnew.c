/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dintnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:03:33 by esterna           #+#    #+#             */
/*   Updated: 2017/10/17 22:15:06 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				**ft_2dintnew(int rows, int cols)
{
	int i;
	int	n;
	int **tmp;

	i = 0;
	tmp = (int **)malloc(sizeof(int *) * (rows + 1));
	while (i < rows)
	{
		n = 0;
		tmp[i] = (int *)malloc(sizeof(int) * cols);
		while (n <= cols)
		{
			tmp[i][n] = 0;
			n++;
		}
		i++;
	}
	tmp[rows] = NULL;
	return (tmp);
}
