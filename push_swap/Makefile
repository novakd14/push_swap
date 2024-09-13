CC = cc
CFLAGS = -Wall -Wextra -Werror -g -D ERROR_MESSAGES
CLIB_DIR = libft
CLIB = ft

SRCS_DIR = ../push_swap/
TEST_DIR = ../unity_test/

NAME = push_swap
SRCS = main.c input.c clean.c rules.c sort.c bubble_sort.c
HEAD = push_swap.h
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean bclean re test ftest memleak

all: test

$(NAME): $(OBJS)
	make -C $(CLIB_DIR) bonus
	$(CC) -o $(NAME) $(OBJS) -L$(CLIB_DIR) -l$(CLIB)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	clear
	-./$(NAME)
	-./$(NAME) 42
	-./$(NAME) 42 0
	-./$(NAME) 42 100
	-./$(NAME) 42 0 1
	-./$(NAME) 42 0 100
	-./$(NAME) 42 0 1 2
	-./$(NAME) 42 0 1 100
	-./$(NAME) 42 0 1 2 3
	-./$(NAME) 42 0 1 2 100


norm:
	norminette

memleak: $(NAME)
	valgrind -s --leak-check=full --show-leak-kinds=all ./$(NAME) 42 -8 21 -2 -1 0
