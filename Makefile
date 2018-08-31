# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 21:46:51 by hugsbord          #+#    #+#              #
#    Updated: 2018/08/29 17:35:31 by hugsbord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
		checker.c \
		parser.c \
		tetriminos.c \
		solver.c

LIB = libft.a

DIRLIB = libft/

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		@echo "\033[32m>>\033[0m \033[33mStarting library & fillit\033[32m compilation\033[0m \033[0m"
		@make $(DIRLIB)
		@gcc -c $(SRC)
		@gcc -o $(NAME) $(OBJ) $(LIB)
		@echo "\033[32m>> Fillit correctly created ... OK\033[0m"

clean:
		@rm -f $(OBJ)
		@echo "\033[32mObjects \033[31mremoved\033[0m"

fclean: clean
		@rm -f $(NAME)
		@echo "\033[32m$(NAME) \033[31mremoved\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
