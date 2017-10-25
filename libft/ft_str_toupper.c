/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:46:53 by esterna           #+#    #+#             */
/*   Updated: 2017/10/20 20:30:37 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
