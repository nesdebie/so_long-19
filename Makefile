SRC = 	src/main.c \
		src/char_checker.c \
		src/sprites_drawer.c \
		src/utils.c \
		src/exits.c \
		src/steps_counter.c \
		src/ft_mlx.c \
		src/init_game.c \
		src/init_img.c \
		src/map_checker.c \
		src/map_reader.c \
		src/map_drawer.c \
		src/ft_move.c \
		libft/ft_itoa.c \
		libft/ft_calloc.c \
		libft/ft_putchar_fd.c \
		libft/ft_strchr.c \
		libft/ft_bzero.c \
		libft/ft_strjoin.c \
		libft/ft_strlen.c \
		libft/ft_strnstr.c \
		libft/ft_putstr_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_strdup.c \
		libft/ft_strncmp.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c 

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = ./includes/so_long.h

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLXFLAGS) -o $(NAME)
	@echo "Compilation completed and so_long is ready to use.\n"

%.o: %.c
	@${CC} ${CFLAGS} -Imlx -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "cleaned"

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo "fcleaned"

re: fclean all

.PHONY: all clean fclean re
