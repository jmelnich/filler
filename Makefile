# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 13:34:52 by imelnych          #+#    #+#              #
#    Updated: 2018/02/05 12:34:23 by imelnych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Your Makefile will have to compile the library, and then compile your project???

NAME = libfiller.a
EXC = imelnych.filler
FLAGS = -Wall -Wextra -Wextra
OBJ_DIR = ./obj
LB_PATH = ./libft
SRC_files = filler.c
OBJ_files = $(addprefix $(OBJ_DIR)/, $(SRC_files:.c=.o))

LIB_AR 	= ar rc $(NAME) $(OBJ_files)
INC = fillerflib.h

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	gcc $(FLAGS) -I $(INC) -o $@ -c $<

$(NAME):
	@make -C $(LB_PATH)
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(OBJ_files)
	@$(LIB_AR)
	ranlib $(NAME)
	# gcc -o $(EXC) $(NAME) main.c

clean:
	@make -C $(LB_PATH) clean
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LB_PATH) fclean
	/bin/rm -rf $(NAME)
	@echo $(NAME) "deleted"

re: fclean all