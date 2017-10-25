/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 21:37:37 by esterna           #+#    #+#             */
/*   Updated: 2017/10/17 21:40:37 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_count_words(char *str)
{
	int n;

	n = 0;
	while (*str != '\0')
	{
		while (ft_isspace(*str) == 1 && *str != '\0')
			str++;
		if (*str != '\0')
			n++;
		while (ft_isspace(*str) != 1 && *str != '\0')
			str++;
	}
	return (n);
}
