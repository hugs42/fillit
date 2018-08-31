# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 21:46:51 by hugsbord          #+#    #+#              #
#    Updated: 2018/08/31 16:02:11 by hugsbord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC_PATH = ./
OBJ_PATH = ./
CPPFLAGS = -Iinclude
LDFLAGS = -L./libft
LDLIBS = -lft
CFLAGS = -Wall -Wextra -Werror
CC = clang
SRC_NAME = main.c \
		checker.c \
		parser.c \
		tetriminos.c \
		solver.c \
		free.c \

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32m>>\033[0m \033[33mStarting library & fillit\033[32m compilation\033[0m \033[0m"
	@make -C libft
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "\033[32m>> Fillit correctly created ... OK\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm $(OBJ)
	make -C libft clean
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[32mObjects \033[31mremoved\033[0m"

fclean: clean
	@rm -fv $(NAME)
	make -C libft fclean
	@echo "\033[32m$(NAME) \033[31mremoved\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
