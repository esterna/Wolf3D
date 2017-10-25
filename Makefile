#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esterna <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 17:01:46 by esterna           #+#    #+#              #
#    Updated: 2017/10/24 22:05:09 by esterna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CFLAGS = -Wall -Wextra -Werror -framework OpenGL -framework Appkit 

DEPS = libft/libft.a\
	   minilibx_macos_10.11/libmlx.a

DEBUG = -g -fsanitize=address

FUNCTIONS = $(wildcard *.c)

all: $(NAME)

libs:
	@make -C libft/
	@make -C minilibx_macos_10.11/

debug:
	@gcc $(CFLAGS) $(DEBUG) -o $(NAME) $(FUNCTIONS) $(DEPS)

$(NAME): libs
	@gcc $(CFLAGS) -o $(NAME) $(FUNCTIONS) $(DEPS)

clean:
	@make -C libft/ clean
	@make -C minilibx_macos_10.11/ clean

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf $(NAME).dSYM

d_clean:
	@/bin/rm -f $(NAME)
	@/bin/rm -rf $(NAME).dSYM

re: fclean all

d_re: d_clean debug
