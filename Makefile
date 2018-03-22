# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 13:34:52 by imelnych          #+#    #+#              #
#    Updated: 2018/03/22 10:57:03 by imelnych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = imelnych.filler
FLAGS = -Wall -Wextra -Wextra
OBJ_DIR = ./obj
LB_DIR = ./libs
SRC_DIR = ./src
INC_DIR = ./includes
LIBFT =  $(LB_DIR)/libft
SRC_files = filler.c map.c players.c denote_piece.c move.c place_piece_algo.c \
			trim_save_piece.c
OBJ_files = $(SRC_files:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_files))

VISUAL = visual
OBJ_DIR_VISUAL = ./obj_visual
SRC_files_visual = visual.c helper.c
OBJ_files_visual = $(SRC_files_visual:.c=.o)
OBJ_VISUAL = $(addprefix $(OBJ_DIR_VISUAL)/, $(OBJ_files_visual))



$(NAME): obj libftbuild $(OBJ) $(VISUAL)
	@echo "\x1b[0;35mCreating my bot\x1B[0m"
	@gcc $(FLAGS) $(OBJ) -L $(LIBFT) -lft -I $(INC_DIR) -o $(NAME)
	@echo "\x1b[0;35mPut bot to players\x1B[0m"
	@cp $(NAME) players/

$(VISUAL): obj_visual $(OBJ_VISUAL)
	@echo "\x1b[0;35mCreating visualization\x1B[0m"
	@gcc $(FLAGS) $(OBJ_VISUAL) -L $(LIBFT) -lft -I $(INC_DIR) -o $(VISUAL)

all: $(NAME) $(VISUAL)

obj:
	@mkdir -p $(OBJ_DIR)

libftbuild:
	@make -C $(LIBFT)

obj_visual:
	@mkdir -p $(OBJ_DIR_VISUAL)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "\x1b[0;32mCompilled:\x1B[0m \x1b[0;36m$<\x1B[0m"
	gcc $(FLAGS) -I  $(INC_DIR) -o $@ -c $<

$(OBJ_DIR_VISUAL)/%.o: $(SRC_DIR)/%.c
	@echo "\x1b[0;32mCompilled:\x1B[0m \x1b[0;36m$<\x1B[0m"
	gcc $(FLAGS) -I  $(INC_DIR) -o $@ -c $<

clean:
	@make -C $(LIBFT) clean
	@echo "\x1B[3;31mCleaning Filler objects\x1B[0m"
	/bin/rm -rf $(OBJ_DIR)
	@echo "\x1B[3;31mCleaning Visual objects\x1B[0m"
	/bin/rm -rf $(OBJ_DIR_VISUAL)

fclean: clean
	@make -C $(LIBFT) fclean
	@echo "\x1B[3;31mDeleting my player\x1B[0m"
	/bin/rm -rf $(NAME)
	/bin/rm -f players/$(NAME)
	@echo "\x1B[3;31mDeleting visualization\x1B[0m"
	/bin/rm -f $(VISUAL)

re: fclean all


