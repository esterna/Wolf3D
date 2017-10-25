# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esterna <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 17:01:46 by esterna           #+#    #+#              #
#    Updated: 2017/10/20 20:43:05 by esterna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
CFLAGS = -Wall -Wextra -Werror
DEPS = libft.h
FUNCTIONS = $(wildcard *.c)
OBJ = $(FUNCTIONS:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -c $(FUNCTIONS) $(DEPS)
	@ar rc $@.a $(OBJ)
	@ranlib $@.a

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME).a
	@/bin/rm -f $(NAME).h.gch

re: fclean all
