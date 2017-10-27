/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:08:42 by esterna           #+#    #+#             */
/*   Updated: 2017/08/23 00:03:13 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_format	(*g_pr[127]) (char *str, char ch, t_format format) =
{
	['i'] = printi,
	['d'] = printi,
	['D'] = printi,
	['O'] = printi,
	['o'] = printi,
	['x'] = printi,
	['X'] = printi,
	['u'] = printi,
	['U'] = printi,
	['p'] = printi,
	['b'] = printi,
	['a'] = printd,
	['A'] = printd,
	['e'] = printd,
	['E'] = printd,
	['f'] = printd,
	['F'] = printd,
	['g'] = printd,
	['G'] = printd
};

char		*(*g_sort[127]) (t_format format, va_list arg) =
{
	['i'] = sort_i,
	['d'] = sort_i,
	['D'] = sort_i,
	['O'] = sort_x,
	['o'] = sort_x,
	['x'] = sort_x,
	['X'] = sort_x,
	['u'] = sort_u,
	['U'] = sort_u,
	['a'] = sort_d,
	['A'] = sort_d,
	['e'] = sort_d,
	['E'] = sort_d,
	['f'] = sort_d,
	['F'] = sort_d,
	['g'] = sort_d,
	['G'] = sort_d,
	['b'] = sort_b
};

t_format	(*g_sort_pns[127]) (t_format format, va_list arg) =
{
	['p'] = sort_p,
	['C'] = sort_s,
	['c'] = sort_s,
	['s'] = sort_s,
	['S'] = sort_s,
	['%'] = sort_s,
	['n'] = sort_n
};

t_format		parse_data(t_format format, va_list arg)
{
	char	*tmp;

	if (g_sort[(int)format.specifier] != NULL)
	{
		tmp = (*g_sort[(int)format.specifier])(format, arg);
		format = (*g_pr[(int)format.specifier])(tmp, format.specifier, format);
	}
	else if (g_sort_pns[(int)format.specifier] != NULL)
		format = (*g_sort_pns[(int)format.specifier])(format, arg);
	else
	{
		ft_putchar('%');
		ft_putchar(format.specifier);
		format.n += 2;
	}
	return (format);
}

t_format		print_curr(char **current, t_format format)
{
	char *tmp;

	while (**current != '%' && **current != '\0')
	{
		if (**current == '{' && (tmp = find_color(ft_strsub(*current + 1, 0,
							ft_strchr(*current, '}') - *current - 1))) != NULL)
		{
			print_colors(tmp);
			*current += ft_strlen(tmp) + 2;
			free((void *)tmp);
		}
		else if (**current == '{' && ft_strcmp(ft_strsub(*current, 0,
						ft_strchr(*current, '}') - *current + 1), "{eoc}") == 0)
		{
			ft_putstr("\e[0m");
			*current += 5;
		}
		if (**current == '\0' || **current == '%')
			break ;
		ft_putchar(**current);
		(*current)++;
		format.n++;
	}
	return (format);
}

t_format		initialise_format(t_format format)
{
	format.pad = 0;
	format.sign = 0;
	format.width = 0;
	format.prefix = 0;
	format.precision = -1;
	format.length = 0;
	format.ptr = NULL;
	return (format);
}

int				ft_printf(const char *current, ...)
{
	t_format	format;
	va_list		arg;

	format.n = 0;
	va_start(arg, current);
	while (*current)
	{
		format = initialise_format(format);
		format = print_curr((char **)&current, format);
		if (!*current || (*current == '%' && *(current + 1) == '\0'))
			break ;
		current++;
		format = find_format((char **)&current, format, arg);
		if (!*current)
			break ;
		format.specifier = *current;
		if (ft_strchr(SPECS, *current) && *current != '\0')
		{
			format = parse_data(format, arg);
			current++;
		}
	}
	va_end(arg);
	return (format.n);
}
