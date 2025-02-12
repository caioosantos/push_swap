NAME = libftprintf.a
LIB = ar rcs
CC = cc
FLAGS = -Wall -Werror -Wextra

SRCS =	ft_printf.c \
		ft_printchar.c \
		ft_printstr.c \
		ft_printnbr.c \
		ft_printhex.c \
		ft_printptr.c

SRCS_BONUS =	bonus_printf/ft_printf_bonus.c \
				bonus_printf/ft_printchar_bonus.c \
				bonus_printf/ft_printstr_bonus.c \
				bonus_printf/ft_printnbr_bonus.c \
				bonus_printf/ft_printhex_bonus.c \
				bonus_printf/ft_printptr_bonus.c

OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

INCLUDES =	ft_printf.h \
			ft_printf_bonus.h

BONUS_ADDED = .bonus

all: $(NAME)

$(NAME): $(OBJECTS)
	$(LIB) $(NAME) $(OBJECTS)

bonus: $(BONUS_ADDED)

$(BONUS_ADDED): $(OBJECTS_BONUS)
	$(LIB) $(NAME) $(OBJECTS_BONUS)
	touch $(BONUS_ADDED)

%.o: %.c INCLUDES
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

