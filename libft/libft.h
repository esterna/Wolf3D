/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esterna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:04:48 by esterna           #+#    #+#             */
/*   Updated: 2017/10/20 20:47:20 by esterna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

/*
**Chained Lists
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

int					ft_lstsize(t_list *begin_list);

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstaddend(t_list **alst, t_list *new);

t_list				*ft_lstfind(t_list *begin_list, void *data_ref,
								int (*cmp)());

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Conversion Functions
*/
double				ft_atod(char *nbr);

size_t				ft_atoi(const char *str);

size_t				ft_atoi_base(const char *n, int b);

char				*ft_dtoa_base(double dbl, int base, int precision);

int					ft_nbrsize_base(int n, int base);

int					ft_tolower(int c);

char				*ft_str_tolower(char *str);

char				*ft_str_toupper(char *str);

int					ft_toupper(int c);

char				*ft_itoa(int n);

char				*ft_itoa_base(int n, int base);

char				*ft_dtosf_base(double dbl, int base, int precision);

char				*ft_ulltoa_base(unsigned long long n, char sign, int base);

/*
** Identity Functions
*/
int					ft_isalnum(int n);

int					ft_isalpha(int n);

int					ft_isascii(int n);

int					ft_isdigit(int n);

int					ft_isprint(int c);

int					ft_isspace(int c);

/*
**  Memory Manipulation
*/
int					**ft_2dintnew(int rows, int cols);

char				**ft_2dstrnew(int lines, int chars);

void				ft_bzero(void *src, size_t n);

int					*ft_intnew(int size);

void				*ft_memccpy(void *dest, const void *src, int c, size_t n);

void				*ft_memchr(const void *str, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memcpy(void *dest, const void *src, size_t n);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

void				*ft_memmove(void *dest, const void *src, size_t n);

void				*ft_memset(void *src, int c, size_t n);

void				ft_swap(int *a, int *b);

void				ft_free_array(void **array, size_t n);

/*
** Math Functions
*/
int					dbl_frac_size(double dbl, int base, int precision);

int					dbl_front_size(double dbl, int base);

int					find_exponent(double dbl, int base);

int					ft_abs(int n);

double				ft_abs_dbl(double n);

double				ft_fmod(double nb, double div);

int					ft_gcd(int a, int b);

double				ft_modf(double x, double *integer);

double				ft_pow(double base, double exp);

int					ft_roundi(int a, int b);

double				ft_sqrt(double n);

double				ft_round_dbl(double dbl, int precision);

/*
**  Printing Functions
*/
void				ft_putchar(char c);

void				ft_putnbr(int nb);

void				ft_putnstr(char *str, int n);

void				ft_putstr(const char *str);

void				ft_putendl(char const *s);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr_fd(int n, int fd);

void				ft_putnstr(char *str, int n);

void				ft_put_int_array(int **array, int n);

void				ft_put_str_array(char **array);

/*
** String Manipulation
*/
int					ft_count_words(char *str);

void				ft_putwchar(wchar_t ch);

void				ft_putwchar_fd(wchar_t ch, int fd);

void				ft_putwstr(wchar_t const *str);

void				ft_putwstr_fd(wchar_t const *str, int fd);

size_t				ft_wstrlen(const wchar_t *str);

char				*ft_strcat(char *dest, const char *src);

char				*ft_strchr(const char *str, int c);

char				*ft_strcpy(char *dest, const char *src);

char				*ft_strdup(const char *src);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

size_t				ft_strlcat(char *dest, const char *src, size_t size);

size_t				ft_strlen(const char *str);

char				*ft_strncat(char *dest, const char *src, size_t n);

char				*ft_strncpy(char *dest, const char *src, size_t n);

char				*ft_strnstr(const char *haystack,
								const char *needle, size_t len);

char				*ft_strrchr(const char *str, int c);

char				*ft_strstr(const char *haystack, const char *needle);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s);

char				**ft_strsplit(char const *s, char c);

#endif
