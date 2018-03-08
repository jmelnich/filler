# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 13:34:52 by imelnych          #+#    #+#              #
#    Updated: 2018/03/08 16:42:10 by imelnych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = imelnych.filler
FLAGS = -Wall -Wextra -Wextra
OBJ_DIR = ./obj
LB_DIR = ./libs
SRC_DIR = ./src
INC_DIR = ./includes
LIBFT =  $(LB_DIR)/libft
LB_PF = $(LB_DIR)/ft_printf
SRC_files = filler.c
OBJ_files = $(SRC_files:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_files))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "\x1b[0;32mCompilling:\x1B[0m \x1b[0;36m$<\x1B[0m"
	gcc $(FLAGS) -I  $(INC_DIR) -c $< -o $@

$(NAME):
	@make -C $(LIBFT)
	@make -C $(LB_PF)
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(OBJ)
	@echo "\x1b[0;35mCreating my bot\x1B[0m"
	@gcc $(FLAGS) $(OBJ) -I $(INC_DIR) -L $(LB_PF)/printflib.a -L $(LIBFT) -lft -o $(NAME)
	@echo "\x1b[0;35mPutting bot to players\x1B[0m"
	@cp $(NAME) players/

clean:
	@echo "\x1B[3;31mCleaning LIBFT objects\x1B[0m"
	@make -C $(LIBFT) clean
	@make -C $(LB_PF) clean
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\x1B[3;31mCleaning LIBFT libft.a\x1B[0m"
	@make -C $(LIBFT) fclean
	@make -C $(LB_PF) fclean
	/bin/rm -rf $(NAME)
	/bin/rm -f players/$(NAME)

re: fclean all

test:
	@echo "\x1b[0;35mCreating check file\x1B[0m"
	gcc -o check $(FLAGS) $(SRC_DIR)/$(SRC_files) -I $(INC_DIR)

