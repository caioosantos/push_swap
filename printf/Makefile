NAME = libftprintf.a

SRCS =	ft_printf.c \
		ft_printchar.c \
		ft_printstr.c \
		ft_printnbr.c \
		ft_printhex.c \
		ft_printptr.c \
		ft_printf_utils.c \

OBJ = $(SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
