/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 22:55:05 by esterna           #+#    #+#             */
/*   Updated: 2017/03/03 17:21:53 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *begin_list)
{
	t_list		*current;
	int			n;

	n = 0;
	current = begin_list;
	while (current)
	{
		n++;
		current = current->next;
	}
	return (n);
}
