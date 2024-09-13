CC = cc
CFLAGS = -Wall -Wextra -Werror -g -D ERROR_MESSAGES
CLIB_DIR = libft
CLIB = ft

SRCS_DIR = ../push_swap/
TEST_DIR = ../unity_test/

NAME = push_swap
SRCS = main.c input.c clean.c rules.c sort.c
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
	-./$(NAME) 42 -8 21 -2 -1 0
	-./$(NAME) -8 -2 -1 42 0 21
	-./$(NAME) -8 -2 -1 21 0 42
	-./$(NAME) -8 -2 -1 0 42 21
	-./$(NAME) -8 -2 -1 0 21 42

norm:
	norminette

memleak: $(NAME)
	valgrind -s --leak-check=full --show-leak-kinds=all ./$(NAME) 42 -8 21 -2 -1 0
