# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 13:34:52 by imelnych          #+#    #+#              #
#    Updated: 2018/03/14 11:30:08 by imelnych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = imelnych.filler
FLAGS = -Wall -Wextra -Wextra
OBJ_DIR = ./obj
LB_DIR = ./libs
SRC_DIR = ./src
INC_DIR = ./includes
LIBFT =  $(LB_DIR)/libft
SRC_files = filler.c map.c players.c piece.c move.c place_piece_algo.c
OBJ_files = $(SRC_files:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_files))

$(NAME): obj $(OBJ)
	@make -C $(LIBFT)
	@echo "\x1b[0;35mCreating my bot\x1B[0m"
	@gcc $(FLAGS) $(OBJ) -L $(LIBFT) -lft -I $(INC_DIR) -o $(NAME)
	@echo "\x1b[0;35mPut bot to players\x1B[0m"
	@cp $(NAME) players/

all: $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "\x1b[0;32mCompilled:\x1B[0m \x1b[0;36m$<\x1B[0m"
	gcc $(FLAGS) -I  $(INC_DIR) -o $@ -c $<

clean:
	@echo "\x1B[3;31mCleaning LIBFT objects\x1B[0m"
	@make -C $(LIBFT) clean
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\x1B[3;31mCleaning LIBFT libft.a\x1B[0m"
	@make -C $(LIBFT) fclean
	/bin/rm -rf $(NAME)
	/bin/rm -f players/$(NAME)

re: fclean all


