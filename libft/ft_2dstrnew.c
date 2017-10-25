/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dstrnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:59:06 by esterna           #+#    #+#             */
/*   Updated: 2017/05/16 18:05:50 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_2dstrnew(int lines, int chars)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * (lines + 1));
	while (i < lines)
	{
		tmp[i] = (char *)malloc(sizeof(char) * chars);
		i++;
	}
	tmp[lines] = NULL;
	return (tmp);
}
