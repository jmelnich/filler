# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 13:34:52 by imelnych          #+#    #+#              #
#    Updated: 2018/03/07 19:14:38 by imelnych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = imelnych.filler
FLAGS = -Wall -Wextra -Wextra
OBJ_DIR = ./obj
LB_DIR = ./libft
SRC_DIR = ./src
INC_DIR = ./includes
LIBFT_a = $(LB_DIR)/libft.a
LIBFT_H = $(LB_DIR)/libft.h
SRC_files = filler.c
OBJ_files = $(SRC_files:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_files))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "\x1b[0;32mCompilling:\x1B[0m \x1b[0;36m$<\x1B[0m"
	gcc $(FLAGS) -I $(LIBFT_H) -I $(INC_DIR) -c $< -o $@

$(NAME):
	@make -C $(LB_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(OBJ)
	@echo "\x1b[0;35mCreating my bot\x1B[0m"
	@gcc $(FLAGS) $(OBJ) -o $(NAME) -I $(LIBFT_a)
	@echo "\x1b[0;35mPutting bot to players\x1B[0m"
	@cp $(NAME) players/

clean:
	@echo "\x1B[3;31mCleaning LIBFT objects\x1B[0m"
	@make -C $(LB_DIR) clean
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\x1B[3;31mCleaning LIBFT libft.a\x1B[0m"
	@make -C $(LB_DIR) fclean
	/bin/rm -rf $(NAME)
	/bin/rm -f players/$(NAME)

re: fclean all