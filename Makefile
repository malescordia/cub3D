NAME = cub3D

CC = @cc

CFLAGS = -Wall -Wextra -Werror

SRC = 	src/main.c

OBJ = $(SRC:.c=.o)

LIBFT = inc/libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32m[success]\033[0m cub3D compiled!"
	@make -sC inc/libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	@echo "\033[33m[clean]\033[0m object files removed!"
	@rm -f $(OBJ)
	@make clean -sC inc/libft/

fclean: clean
	@echo "\033[31m[fclean]\033[0m executable file removed!"
	@rm -f $(NAME)
	@make fclean -sC inc/libft/

re: fclean all