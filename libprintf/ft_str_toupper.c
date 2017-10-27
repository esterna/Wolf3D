/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:46:53 by esterna           #+#    #+#             */
/*   Updated: 2017/07/20 14:14:11 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_str_toupper(char *str)
{
	char *tmp;

	tmp = str;
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
	return (tmp);
}
