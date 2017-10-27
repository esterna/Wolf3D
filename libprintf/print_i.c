/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 21:04:10 by esterna           #+#    #+#             */
/*   Updated: 2017/08/22 21:41:44 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int				find_width(char *str, char ch, t_format format)
{
	int width;
	int	strlen;
	int prec;

	prec = format.precision - ft_strlen(str) + ((*str == '-') ? 1 : 0);
	width = format.width;
	strlen = ft_strlen(str)
				+ ((prec > 0) ? prec : 0)
				+ (((ch == 'o' || ch == 'O') && format.prefix) ? 1 : 0)
				+ (((ch == 'x' || ch == 'X' || ch == 'p')
										&& format.prefix) ? 2 : 0)
				- ((format.precision == 0 && *str == '0') ? 1 : 0)
				+ ((format.sign && *str != '-') ? 1 : 0);
	width = (width - strlen >= 0) ? width - strlen : 0;
	return (width);
}

static t_format			put_prefix(char *str, char ch, t_format format)
{
	if (!(ft_strchr(PRINT_X_VALS, ch) || ch == 'p') || format.prefix == 0)
		return (format);
	if (ch == 'p')
	{
		ft_putstr("0x");
		format.n += 2;
	}
	else if (*str == '0')
		return (format);
	else if (ch == 'o' || ch == 'O')
	{
		ft_putchar('0');
		format.n++;
	}
	else if (ch == 'X' || ch == 'x')
	{
		ft_putchar('0');
		ft_putchar(ch);
		format.n += 2;
	}
	return (format);
}

static t_format			format_n(char *str, char ch, t_format format)
{
	int prec;

	prec = format.precision - ft_strlen(str) + ((*str == '-') ? 1 : 0);
	format.n += ((prec > 0) ? prec : 0) +
		((format.width > 0) ? format.width : 0) + ft_strlen(str) -
		((format.precision == 0 && *str == '0') ? 1 : 0) +
		((format.sign && *str != '-' && ch != 'u') ? 1 : 0);
	return (format);
}

static t_format			put_front(char **str, char ch, t_format format)
{
	char wch;

	wch = (format.pad <= 1 || format.precision >= 0) ? ' ' : '0';
	if (format.pad == 0 || (format.pad == 2 && wch == ' '))
	{
		char_repeat(wch, format.width);
		format.width = 0;
	}
	if (format.sign != 0 && **str != '-' && ch != 'u')
		ft_putchar((format.sign == 1) ? ' ' : '+');
	else if (**str == '-' && wch == '0' && (*str)++)
		ft_putchar('-');
	format = put_prefix(*str, ch, format);
	if ((format.pad == 2 || format.pad == 3) && format.width > 0)
	{
		char_repeat(wch, format.width);
		format.width = 0;
	}
	return (format);
}

/*
** Prints all number specifiers with precision and width applied.
*/

t_format				printi(char *str, char ch, t_format format)
{
	char	*tmp;

	tmp = str;
	format.width = find_width(str, ch, format);
	format = format_n(str, ch, format);
	format = put_front(&str, ch, format);
	if (!(format.precision == 0 && *str == '0'))
	{
		if (*str == '-' && str++)
			ft_putchar('-');
		char_repeat('0', format.precision - ft_strlen(str)
								+ ((*str == '-') ? 1 : 0));
		ft_putstr(str);
	}
	if ((format.specifier == 'o' || format.specifier == 'O')
		&& format.prefix == 1 && format.precision == 0 && *str == '0')
	{
		ft_putstr(str);
		format.n++;
	}
	char_repeat((format.pad <= 1 || format.precision >= 0) ?
								' ' : '0', format.width);
	free(tmp);
	return (format);
}
