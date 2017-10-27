# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esterna <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 17:01:46 by esterna           #+#    #+#              #
#    Updated: 2017/09/06 15:58:55 by esterna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf
CFLAGS = -Wall -Wextra -Werror
DEPS = libftprintf.h
FUNCTIONS =	char_repeat.c\
			colors.c\
			dbl_size.c\
			find_exponent.c\
			format_setup.c\
			ft_abs.c\
			ft_abs_dbl.c\
			ft_dtoa_base.c\
			ft_dtosf_base.c\
			ft_fmod.c\
			ft_isdigit.c\
			ft_itoa_base.c\
			ft_modf.c\
			ft_nbrsize_base.c\
			ft_pow.c\
			ft_printf.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putwchar.c\
			ft_putwchar_fd.c\
			ft_putnbr.c\
			ft_putnstr.c\
			ft_putstr.c\
			ft_putwstr.c\
			ft_putwstr_fd.c\
			ft_round_dbl.c\
			ft_round.c\
			ft_str_tolower.c\
			ft_str_toupper.c\
			ft_strchr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdup.c\
			ft_strlen.c\
			ft_strstr.c\
			ft_strnstr.c\
			ft_strsub.c\
			ft_wstrlen.c\
			ft_strnew.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_ulltoa_base.c\
			print_i.c\
			print_d.c\
			print_ws.c\
			sort_diux.c\
			sort_psn.c\
			sort_b.c
OBJ = $(FUNCTIONS:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -c $(FUNCTIONS) $(DEPS)
	@ar rc $@.a $(OBJ)
	@ranlib $@.a

exe:
	@gcc $(CFLAGS) -g -o printf main_test.c $(FUNCTIONS)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f printf
	@/bin/rm -f $(NAME).a
	@/bin/rm -f $(NAME).h.gch
	@/bin/rm -rf printf.dSYM/

re: fclean all
