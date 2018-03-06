NAME = libft.a
SRC = *.c *.h
FLAGS = -Wall -Wextra -Werror
TEST = main_test.c

# Object compilation
$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

t:
	gcc -o test ./tests/$(TEST)
	./test
