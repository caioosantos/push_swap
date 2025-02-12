# Diretórios
SRC_DIR = src/
INCLUDE_DIR = includes/
LIBFT_DIR = libft/
PRINTF_DIR = printf/
OBJ_DIR = obj/

# Coletar arquivos fonte de todos os subdiretórios
SRC =	$(wildcard $(SRC_DIR)utils/*.c) \
		$(wildcard $(SRC_DIR)moves/*.c) \
		$(wildcard $(SRC_DIR)*.c)

# Criar lista de objetos dentro de obj/, mantendo subdiretórios
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

# Nome do executável
NAME = push_swap

# Flags de compilação
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# Bibliotecas
LIBFT = $(LIBFT_DIR)libft.a
PRINTF = $(PRINTF_DIR)libftprintf.a

# Criar diretórios dentro de obj/
OBJ_DIRS = $(sort $(dir $(OBJ)))

# Regras
all: $(NAME)

# Criar os diretórios para os arquivos objeto
$(OBJ_DIRS):
	@mkdir -p $@

# Compilação dos arquivos .o, garantindo que os diretórios existam
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)

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
