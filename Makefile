# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 21:46:51 by hugsbord          #+#    #+#              #
#    Updated: 2018/09/02 15:21:19 by vimucchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CPPFLAGS = -Iinclude
LDFLAGS = -L./libft
LDLIBS = -lft
CFLAGS = -Wall -Wextra -Werror
CC = clang
SRC = \
	 	main.c \
		checker.c \
		parser.c \
		tetriminos.c \
		solver.c \
		tool.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@echo "\033[32m>>\033[0m \033[33mStarting library & fillit\033[32m compilation\033[0m \033[0m"
	@make -C libft
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "\033[32m>> Fillit correctly created ... OK\033[0m"

clean:
	@rm -fv $(OBJ)
	make -C libft clean
	@echo "\033[32mObjects \033[31mremoved\033[0m"

fclean: clean
	@rm -fv $(NAME)
	make -C libft fclean
	@echo "\033[32m$(NAME) \033[31mremoved\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
