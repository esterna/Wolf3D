/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 20:56:27 by esterna           #+#    #+#             */
/*   Updated: 2017/08/17 22:44:30 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_format			format_n(char *str, t_format format)
{
	int width;

	width = format.width - ft_strlen(str);
	format.n += ((width > 0) ? width : 0) + ft_strlen(str)
		+ ((format.prefix && !format.precision) ? 1 : 0);
	return (format);
}

static int				put_dfront(char *str, char ch,
									t_format format, int width)
{
	if (!format.pad && width > 0 && ((format.pad <= 1) ? ' ' : '0') == ' ')
	{
		char_repeat(((format.pad <= 1) ? ' ' : '0'), width);
		width = 0;
	}
	if (format.sign && *str != '-')
		ft_putchar((format.sign == 1) ? ' ' : '+');
	else if (((format.pad <= 1) ? ' ' : '0') == '0')
	{
		if (ch == 'a' || ch == 'A')
		{
			ft_putnstr(str, (*str == '-') ? 3 : 2);
			str = str + ((*str == '-') ? 3 : 2);
		}
		else if (*str == '-' && str++)
			ft_putchar('-');
	}
	if (width > 0 && ((format.pad <= 1) ? ' ' : '0') == '0')
	{
		char_repeat(((format.pad <= 1) ? ' ' : '0'), width);
		width = 0;
	}
	return (width);
}

/*
** Prints all double specifiers with precision and width applied.
*/

t_format				printd(char *str, char ch, t_format format)
{
	int		width;
	char	*tmp;

	tmp = str;
	format = format_n(str, format);
	width = put_dfront(str, ch, format, format.width - ft_strlen(str));
	if (ch == 'e' || ch == 'E')
	{
		ft_putchar(*str);
		str++;
	}
	else if (ch == 'a' || ch == 'A')
	{
		ft_putnstr(str, 3);
		str += 3;
	}
	else if (ch == 'f' || ch == 'F')
		ft_putstr(str);
	if (format.prefix && *str != '.' && format.precision == 0)
		ft_putchar('.');
	if (ch != 'f' && ch != 'F')
		ft_putstr(str);
	char_repeat((format.pad <= 1) ? ' ' : '0', width);
	free(tmp);
	return (format);
}
