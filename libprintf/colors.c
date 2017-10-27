/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 22:24:19 by esterna           #+#    #+#             */
/*   Updated: 2017/08/23 00:08:52 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *g_colors[] = {"red", "green", "yellow", "blue", "magenta", "cyan", "end"};

char			*find_color(char *color)
{
	int i;

	i = 0;
	while (ft_strcmp(g_colors[i], "end") != 0)
	{
		if (ft_strcmp(g_colors[i], color) == 0)
			return (ft_strdup(g_colors[i]));
		i++;
	}
	return (NULL);
}

void			print_colors(char *color)
{
	if (!ft_strcmp(color, "red"))
		ft_putstr("\e[31m");
	else if (!ft_strcmp(color, "green"))
		ft_putstr("\e[32m");
	else if (!ft_strcmp(color, "yellow"))
		ft_putstr("\e[33m");
	else if (!ft_strcmp(color, "blue"))
		ft_putstr("\e[34m");
	else if (!ft_strcmp(color, "cyan"))
		ft_putstr("\e[36m");
	else if (!ft_strcmp(color, "magenta"))
		ft_putstr("\e[35m");
}
