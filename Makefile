SRC_DIR = src/
SRC_BONUS_DIR = src_bonus/
INCLUDE_DIR = includes/
LIBFT_DIR = libft/
PRINTF_DIR = printf/
OBJ_DIR = obj/

SRC =	$(wildcard $(SRC_DIR)utils/*.c) \
		$(wildcard $(SRC_DIR)moves/*.c) \
		$(wildcard $(SRC_DIR)*.c)

SRC_BONUS =	$(wildcard $(SRC_BONUS_DIR)moves/*.c) \
			$(wildcard $(SRC_BONUS_DIR)*.c)

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
OBJ_BONUS = $(patsubst $(SRC_BONUS_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_BONUS))

NAME = push_swap
BONUS_NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

LIBFT = $(LIBFT_DIR)libft.a
PRINTF = $(PRINTF_DIR)libftprintf.a

OBJ_DIRS = $(sort $(dir $(OBJ) $(OBJ_BONUS)))

all: $(NAME)

$(OBJ_DIRS):
	@mkdir -p $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_BONUS_DIR)%.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

$(BONUS_NAME): $(OBJ_BONUS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $(OBJ_BONUS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

bonus: $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
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
