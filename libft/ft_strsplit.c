/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:06:41 by esterna           #+#    #+#             */
/*   Updated: 2017/03/12 21:47:16 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		nbr_words(const char *s, char c)
{
	int n;

	n = 0;
	while (*s)
	{
		if (*s == c)
			while (*s == c && *s)
				s++;
		else
		{
			n++;
			while (*s != c && *s)
				s++;
		}
	}
	return (n);
}

static int		largest_word(const char *s, char c)
{
	int i;
	int largest;

	largest = 0;
	while (*s)
	{
		i = 0;
		if (*s == c)
			while (*s == c && *s)
				s++;
		while (*s != c && *s)
		{
			i++;
			s++;
		}
		if (i > largest)
			largest = i;
	}
	return (largest);
}

static char		**add_words(char **array, char const *s, char c)
{
	int n;
	int i;

	i = 0;
	while (*s)
	{
		n = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			array[i][n] = *s;
			n++;
			s++;
		}
		if ((*s == c || !(*s)) && array[i])
		{
			array[i][n] = '\0';
			i++;
		}
	}
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		words;
	int		largest;
	char	**tmp;

	i = 0;
	if (!s)
		return (NULL);
	words = nbr_words(s, c) + 1;
	largest = largest_word(s, c) + 1;
	tmp = (char **)malloc(sizeof(char *) * words);
	if (!(tmp))
		return (NULL);
	while (i < words)
	{
		tmp[i] = (char *)malloc(sizeof(char) * largest);
		if (!(tmp[i]))
			return (NULL);
		i++;
	}
	tmp[words - 1] = NULL;
	tmp = add_words(tmp, s, c);
	return (tmp);
}
