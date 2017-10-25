/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:37:45 by esterna           #+#    #+#             */
/*   Updated: 2017/07/10 20:53:31 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*ns;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	ns = ft_strnew(len);
	if (!ns)
		return (NULL);
	while (*s1)
	{
		ns[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		ns[i] = *s2;
		s2++;
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
