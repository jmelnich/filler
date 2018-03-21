# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 13:34:52 by imelnych          #+#    #+#              #
#    Updated: 2018/03/21 11:42:21 by imelnych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
OBJ_DIR = ./obj
SRC_files = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strncat.c ft_strchr.c \
		ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_strlcat.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c \
		ft_toupper.c ft_strncpy.c ft_memalloc.c ft_memdel.c ft_strnew.c \
		ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
		ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
		ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
		ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_strrev.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_lstiter.c ft_lstmap.c  ft_isdelim.c get_next_line.c \
		ft_arrnew.c ft_arrdel.c ft_isdigit_char.c ft_numlen_max.c ft_strjoin_free.c \
		print_address.c ft_printf.c print_digits.c print_digits_unsigned.c \
		print_str.c print_unichar.c print_unicode.c check_type.c fill_type.c \
		ft_itoabase.c ft_atoibase.c save_spec.c

OBJ_files = $(SRC_files:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_files))

all: $(NAME)

$(OBJ_DIR)/%.o:%.c
	@gcc $(FLAGS) -c -o $@ $<

$(NAME):
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(OBJ)
	@echo "\x1b[0;35mCreating libft.a\x1B[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\x1b[0;32mlibft has compiled\x1B[0m"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\x1b[0;31mRemoving objects and libft.a\x1B[0m"
	rm -f $(NAME)

re: fclean all