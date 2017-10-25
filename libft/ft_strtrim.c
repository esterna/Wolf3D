/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:51:31 by esterna           #+#    #+#             */
/*   Updated: 2017/03/12 22:11:35 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*first_word(char const *s)
{
	char *tmp;

	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	tmp = (char *)s;
	return (tmp);
}

static char		*last_word(char const *s)
{
	char *tmp;

	tmp = (char *)s;
	while (*s)
		s++;
	s--;
	while ((*s == ' ' || *s == '\n' || *s == '\t') && s != (char const *)tmp)
		s--;
	tmp = (char *)s;
	return (tmp);
}

static int		new_strlen(char *first, char *last, const char *s)
{
	int		n;
	char	*tmp;

	n = 0;
	tmp = first;
	if ((last - 1) == s && !(*first))
		return (0);
	while (tmp != last)
	{
		tmp++;
		n++;
	}
	return (n);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	char	*tmp;
	char	*first;
	char	*last;
	int		len;

	i = 0;
	if (!s)
		return (NULL);
	first = first_word(s);
	last = last_word(s) + 1;
	len = new_strlen(first, last, s);
	if (len == 0)
		return (ft_strdup(""));
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	while (*s && s != first)
		s++;
	while (*s && s != last)
		tmp[i++] = *s++;
	tmp[i] = '\0';
	return (tmp);
}
