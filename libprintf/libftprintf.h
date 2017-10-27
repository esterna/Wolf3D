/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:54:30 by esterna           #+#    #+#             */
/*   Updated: 2017/08/31 19:20:32 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>
# include <wchar.h>

# define SPECS "%sSpdDioOuUxXcCeEfFgGaAbrkn"
# define FLAGS "-+ #0"
# define LENGTH "hljzL"
# define PRINT_S_VALS "SsCc%"
# define PRINT_I_VALS "Ddi"
# define PRINT_D_VALS "aAeEfFgG"
# define PRINT_X_VALS "OoXx"
# define COLORS "red green yellow blue magenta cyan"

typedef	struct	s_format
{
	char	specifier;
	int		pad;
	int		sign;
	int		width;
	int		prefix;
	int		precision;
	int		n;
	int		length;
	char	*ptr;
}				t_format;

int				ft_isdigit(int n);

/*
** String manipulation
*/

char			*ft_strchr(const char *str, int c);

int				ft_strcmp(const char *s1, const char *s2);

char			*ft_strcpy(char *dest, const char *src);

char			*ft_strdup(const char *src);

size_t			ft_strlen(const char *str);

size_t			ft_wstrlen(const wchar_t *str);

char			*ft_strstr(const char *haystack, const char *needle);

char			*ft_strnstr(const char *haystack, const char *needle,
							size_t len);

char			*ft_strnew(size_t size);

char			*ft_strsub(char const *s, unsigned int start, size_t len);

char			*ft_str_tolower(char *str);

char			*ft_str_toupper(char *str);

int				ft_tolower(int c);

int				ft_toupper(int c);

/*
** Conversion functions
*/

char			*find_color(char *color);

int				find_exponent(double dbl, int base);

int				ft_abs(int n);

int				dbl_front_size(double dbl, int base);

int				dbl_frac_size(double dbl, int base, int precision);

char			*ft_dtoa_base(double dbl, int base, int precision);

char			*ft_dtosf_base(double dbl, int base, int precision);

double			ft_fmod(double nb, double div);

char			*ft_itoa_base(int n, int base);

double			ft_modf(double x, double *integer);

double			ft_pow(double base, double exp);

double			ft_round(double dbl);

double			ft_round_dbl(double dbl, int precision);

char			*ft_ulltoa_base(unsigned long long n, char sign, int base);

/*
** Format Functions
*/

t_format		find_format(char **current, t_format format, va_list arg);

t_format		initialise_format(t_format format);

t_format		format_length(char **current, t_format format);

t_format		format_precision(char **current, t_format format, va_list arg);

t_format		format_width(char **current, t_format format, va_list arg);

/*
** Printing Functions
*/

void			char_repeat(char ch, int n);

void			print_colors(char *color);

int				ft_printf(const char *format, ...);

t_format		printd(char *str, char ch, t_format format);

t_format		printi(char *str, char ch, t_format format);

t_format		prints(char *str, char ch, t_format format);

t_format		printws(wchar_t *str, wchar_t ch, t_format format);

int				ft_nbrsize_base(int n, int base);

void			ft_putchar(char c);

void			ft_putchar_fd(char c, int fd);

void			ft_putwchar(wchar_t ch);

void			ft_putwchar_fd(wchar_t ch, int fd);

void			ft_putnbr(int nb);

void			ft_putnstr(char *str, int n);

void			ft_putstr(char const *str);

void			ft_putwstr(wchar_t const *str);

void			ft_putwstr_fd(wchar_t const *str, int fd);

/*
** Length Sorting Functions
*/

char			*sort_i(t_format format, va_list arg);

char			*sort_d(t_format format, va_list arg);

t_format		sort_n(t_format format, va_list arg);

t_format		sort_p(t_format format, va_list arg);

t_format		sort_s(t_format format, va_list arg);

char			*sort_u(t_format format, va_list arg);

char			*sort_x(t_format format, va_list arg);

char			*sort_b(t_format format, va_list arg);

#endif
