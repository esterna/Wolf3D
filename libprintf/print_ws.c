/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 16:22:10 by esterna           #+#    #+#             */
/*   Updated: 2017/08/22 21:42:44 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_format			find_width(char *str, t_format format)
{
	int		prec;

	if (!str)
		prec = 0;
	else
		prec = format.precision < 0 || format.precision > (int)ft_strlen(str)
									? ft_strlen(str) : format.precision;
	format.width = format.width - ((!str) ? 1 : prec);
	format.n += (format.width >= 0 ? format.width : 0);
	return (format);
}

/*
** Prints all string and character specifiers with precision and width applied
*/

t_format				prints(char *str, char ch, t_format format)
{
	format = find_width(str, format);
	if ((!format.pad || format.pad == 2) && format.width > 0)
	{
		char_repeat((format.pad <= 1 || format.precision >= 0)
									? ' ' : '0', format.width);
		format.width = 0;
	}
	if (!str)
	{
		ft_putchar(ch);
		format.n++;
	}
	else
	{
		ft_putnstr(str, (format.precision < 0) ?
				ft_strlen(str) : format.precision);
		format.n += (format.precision < 0 || format.precision
					> (int)ft_strlen(str)) ? ft_strlen(str) : format.precision;
	}
	if (format.width > 0)
		char_repeat((format.pad <= 1 || format.precision >= 0)
									? ' ' : '0', format.width);
	return (format);
}

static t_format			find_ws_width(wchar_t *str, t_format format)
{
	int		prec;

	if (!str)
		prec = 0;
	else
		prec = format.precision < 0 || format.precision > (int)ft_wstrlen(str)
									? ft_wstrlen(str) : format.precision;
	format.width -= (!str) ? 1 : prec;
	format.n += format.width;
	return (format);
}

static void				ft_putnwstr(wchar_t *str, int n)
{
	while (*str != '\0' && n)
	{
		ft_putwchar(*str);
		str++;
		n--;
	}
}

/*
**	Prints all wide characters and wide character strings
**	with width and precision applied
*/

t_format				printws(wchar_t *str, wchar_t ch, t_format format)
{
	format = find_ws_width(str, format);
	if ((!format.pad || format.pad == 2) && format.width > 0)
	{
		char_repeat(' ', format.width);
		format.width = 0;
	}
	if (!str)
	{
		ft_putwchar(ch);
		format.n++;
	}
	else
	{
		if (format.precision < 0)
			ft_putwstr(str);
		else
			ft_putnwstr(str, format.precision);
		format.n += (format.precision < 0) ? ft_wstrlen(str) : format.precision;
	}
	if (format.width > 0)
		char_repeat(' ', format.width);
	return (format);
}
