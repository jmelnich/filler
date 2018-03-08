# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/19 13:18:52 by imelnych          #+#    #+#              #
#    Updated: 2018/03/08 16:31:04 by imelnych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXC = ft_printf
FLAGS = -Wall -Wextra -Wextra
OBJ_DIR	= ./obj
SRC_files = ft_printf.c ft_putchar.c ft_strlen.c ft_strnew.c ft_bzero.c \
			ft_isdigitchar.c save_spec.c ft_atoi.c check_type.c fill_type.c \
			ft_numlenmax.c print_digits.c print_digits_unsigned.c ft_atoibase.c \
			print_str.c ft_itoabase.c ft_strdup.c ft_strjoin_free.c ft_putstr.c\
			print_address.c print_unichar.c print_unicode.c \


OBJ_files = $(addprefix $(OBJ_DIR)/, $(SRC_files:.c=.o))
LIB_AR 	= ar rc $(NAME) $(OBJ_files) $(OBJ_utils_files)
INC_U = printflib.h

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<

$(NAME):
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(OBJ_files)
	@$(LIB_AR)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
