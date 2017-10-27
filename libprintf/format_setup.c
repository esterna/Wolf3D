/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 21:55:32 by esterna           #+#    #+#             */
/*   Updated: 2017/08/22 17:56:38 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void			nbr_ff(char **str)
{
	while (ft_isdigit(**str) == 1)
		(*str)++;
}

/*
** Checks for both format and width. Updates format struct.
** sign:	 0	: no sign
**			 1	: preface with a space for positive numbers
**			 2	: sign all numbers, '+' in front of positives, etc.
**	prefix:  0	: no prefix
** 		 	 1	: prefix all numbers
**	pad:	 0	: default right-justification and padding with spaces
**			 1	: left-justify the object
**		 	 2  : pads the number with zeroes instead of spaces
**			 3+ : Both
** width:	 #	: Minimum number of characters to be printed.
**				  If the value to be printed is shorter than this number,
**				  the result is padded with blank spaces.
**				  The value is not truncated even if the result is larger.
*/

t_format			format_width(char **current, t_format format, va_list arg)
{
	while (ft_strchr(FLAGS, **current) && **current != '\0')
	{
		if (**current == '-')
			format.pad = 1;
		if (**current == '0' && format.pad == 0)
			format.pad = 2;
		if (**current == ' ')
			if (!format.sign)
				format.sign = 1;
		if (**current == '+')
			format.sign = 2;
		if (**current == '#')
			format.prefix = 1;
		(*current)++;
	}
	while ('0' <= **current && **current <= '9')
	{
		format.width = (format.width * 10) + (**current - '0');
		(*current)++;
	}
	if (**current == '*')
		format.width = va_arg(arg, int);
	(*current) = (*current) + ((**current == '*') ? 1 : 0);
	nbr_ff(current);
	return (format);
}

/*
** For integer specifiers (d, i, o, u, x, X) −
** precision specifies the minimum number of digits to be written.
** If the value to be written is shorter than
** this number, the result is padded with leading zeros.
** The value is not truncated even if the result is longer.
** A precision of 0 means that no character is written for the value 0.
**
** For e, E and f specifiers − this is the number of
** digits to be printed after the decimal point.
**
** For g and G specifiers − This is the maximum
** number of significant digits to be printed.
**
** For s − this is the maximum number of
** characters to be printed.
** By default all characters are printed
** until the ending null character is encountered.
**
** For c type − it has no effect. When no
** precision is specified, the default is 1.
**
** If the period is specified without
** an explicit value for precision, 0 is assumed.
*/

t_format			format_precision(char **current, t_format format,
										va_list arg)
{
	(*current)++;
	format.precision = 0;
	while ('0' <= **current && **current <= '9')
	{
		format.precision = (format.precision * 10) + (**current - '0');
		(*current)++;
	}
	if (**current == '*')
	{
		format.precision = va_arg(arg, int);
		(*current)++;
		while (ft_isdigit(**current) == 1)
			(*current)++;
	}
	return (format);
}

/*
** Specifies how the argument is to interpreted.
** See: http://www.cplusplus.com/reference/cstdio/printf/
** hh : -2
** h  : -1
** l  :  1
** ll :  2
** j  :  3
** z  :  4
** Length is intitialized as 0, representing no length modification.
** How the length changes the argument representation will depend on
** on the specifier and will be sorted appropriately.
*/

t_format			format_length(char **current, t_format format)
{
	while (**current != '\0' && ft_strchr(LENGTH, **current))
	{
		if (**current == 'h' && *(*current + 1) == 'h')
			format.length = (format.length == 0) ? -2 : format.length;
		else if (**current == 'h')
			format.length = (format.length == 0 || format.length < -1)
											? -1 : format.length;
		if (**current == 'l' && *(*current + 1) == 'l')
			format.length = (format.length == 0 || format.length < 2)
											? 2 : format.length;
		else if (**current == 'l' || **current == 'L')
			format.length = (format.length == 0 || format.length < 1)
											? 1 : format.length;
		if (**current == 'j')
			format.length = (format.length == 0 || format.length < 3)
											? 3 : format.length;
		if (**current == 'z')
			format.length = 4;
		(*current) += (**current == *(*current + 1)) ? 2 : 1;
	}
	return (format);
}

t_format			find_format(char **current, t_format format, va_list arg)
{
	while ((ft_strchr(FLAGS, **current) || ft_isdigit(**current)
			|| **current == '.' || ft_strchr(LENGTH, **current)
			|| **current == '*') && **current != '\0')
	{
		if (ft_strchr(FLAGS, **current) || ft_isdigit(**current)
										|| **current == '*')
			format = format_width(current, format, arg);
		if (**current == '.')
			format = format_precision(current, format, arg);
		if (ft_strchr(LENGTH, **current) && **current != '\0')
			format = format_length(current, format);
	}
	return (format);
}
