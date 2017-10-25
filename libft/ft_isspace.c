/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:10:28 by esterna           #+#    #+#             */
/*   Updated: 2017/10/22 18:34:22 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int ch)
{
	unsigned char test;

	test = (unsigned char)ch;
	if (test == '\t' || test == '\n'
			|| test == '\v' || test == '\f'
			|| test == '\r'
			|| test == ' ')
		return (1);
	return (0);
}
