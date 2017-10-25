/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 14:04:06 by esterna           #+#    #+#             */
/*   Updated: 2017/07/10 21:47:02 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <limits.h>

char			**setup_line(char **line, char **overflow)
{
	int		i;

	i = 0;
	while ((*overflow)[i] != '\n' && (*overflow)[i])
		i++;
	*line = ft_strncpy(ft_strnew(i), *overflow, i);
	return (overflow);
}

void			fill_overflow(char **overflow)
{
	char	*end;
	char	*tmp;

	if ((end = ft_strchr(*overflow, '\n')))
	{
		tmp = ft_strdup(end + 1);
		ft_strclr(*overflow);
		ft_strdel(overflow);
		*overflow = tmp;
	}
	else
	{
		ft_strdel(overflow);
		*overflow = NULL;
	}
}

int				get_next_line(const int fd, char **line)
{
	int				rd;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	static char		*overflow[MAX_FD];

	if (fd < 0 || fd > MAX_FD || BUFF_SIZE < 1 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!(overflow[fd]))
		overflow[fd] = ft_strnew(BUFF_SIZE);
	while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		tmp = ft_strjoin(overflow[fd], buf);
		ft_strdel(overflow + fd);
		overflow[fd] = tmp;
		if ((tmp = ft_strchr(overflow[fd], '\n')))
			break ;
	}
	if ((rd == 0 && overflow[fd][0] == 0) || rd < 0)
	{
		ft_strdel(overflow + fd);
		return (rd);
	}
	fill_overflow(setup_line(line, overflow + fd));
	return (1);
}
