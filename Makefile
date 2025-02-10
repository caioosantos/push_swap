# Diretórios
SRC_DIR = src
INCLUDE_DIR = includes
LIBFT_DIR = libft
PRINTF_DIR = printf

# Arquivos fonte
SRCS =	$(wildcard $(SRC_DIR)/*.c) \
		$(wildcard $(SRC_DIR)/utils/*.c) \
		$(wildcard $(SRC_DIR)/moves/*.c) \

# Arquivos objeto
OBJ = $(SRCS:.c=.o)

# Nome do executável
NAME = push_swap

# Flags de compilação
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# Bibliotecas
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Regras
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

# Regra para gerar arquivos .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re: fclean all

test2: $(NAME)
		$(eval ARG = $(shell shuf -i 0-100 -n 2))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Moves: "
		@./push_swap $(ARG) | wc -l

test3: $(NAME)
		$(eval ARG = $(shell shuf -i 0-100 -n 3))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Moves: "
		@./push_swap $(ARG) | wc -l

test5: $(NAME)
		$(eval ARG = $(shell shuf -i 0-5000 -n 5))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Moves: "
		@./push_swap $(ARG) | wc -l

test100: $(NAME)
		$(eval ARG = $(shell shuf -i 0-5000 -n 100))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Moves: "
		@./push_swap $(ARG) | wc -l

test500: $(NAME)
		$(eval ARG = $(shell shuf -i 0-5000 -n 500))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Moves: "
		@./push_swap $(ARG) | wc -l

test1000: $(NAME)
		$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Moves: "
		@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re
