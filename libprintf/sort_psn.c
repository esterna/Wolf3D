/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_psn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 17:31:42 by esterna           #+#    #+#             */
/*   Updated: 2017/08/22 21:40:42 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_format		sort_s(t_format format, va_list arg)
{
	wchar_t		*wstr;
	char		*str;

	if ((format.length == 1 && format.specifier == 'c')
			|| format.specifier == 'C')
		format = printws(NULL, va_arg(arg, wchar_t), format);
	else if ((format.length == 1 && format.specifier == 's')
			|| format.specifier == 'S')
	{
		wstr = va_arg(arg, wchar_t *);
		format = (!wstr) ? prints("(null)", 's', format)
							: printws(wstr, 'S', format);
	}
	else if (format.specifier == '%')
		format = prints(NULL, format.specifier, format);
	else if (format.specifier == 'c')
		format = prints(NULL, va_arg(arg, int), format);
	else
	{
		str = va_arg(arg, char *);
		format = prints((!str) ? "(null)" : str, 's', format);
	}
	return (format);
}

t_format		sort_p(t_format format, va_list arg)
{
	void *ptr;

	ptr = va_arg(arg, void *);
	format.prefix = 1;
	if (!ptr)
		format = printi(ft_strdup("0"), 'p', format);
	else
		format = printi(ft_str_tolower(ft_ulltoa_base(
						(unsigned long int)ptr, 'p', 16)), 'p', format);
	return (format);
}

t_format		sort_n(t_format format, va_list arg)
{
	if (format.length == -2)
		*(va_arg(arg, signed char *)) = format.n;
	else if (format.length == -1)
		*(va_arg(arg, short int *)) = format.n;
	else if (format.length == 0)
		*(va_arg(arg, int *)) = format.n;
	else if (format.length == 1)
		*(va_arg(arg, long int *)) = format.n;
	else if (format.length == 2)
		*(va_arg(arg, long long int *)) = format.n;
	else if (format.length == 3)
		*(va_arg(arg, intmax_t *)) = format.n;
	else if (format.length == 4)
		*(va_arg(arg, size_t *)) = format.n;
	return (format);
}
