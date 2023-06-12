NAME = so_long

SRCS = 	src/main.c \
		src/checkers/char_checker.c \
		src/checkers/path_checker.c \
		src/drawers/sprites_drawer.c \
		src/utils.c \
		src/exits.c \
		src/drawers/steps_counter.c \
		src/drawers/ft_mlx.c \
		src/init_files/init_game.c \
		src/init_files/init_img.c \
		src/checkers/map_checker.c \
		src/checkers/map_reader.c \
		src/drawers/map_drawer.c \
		src/drawers/ft_move.c

OBJS 	= $(SRCS:.c=.o)

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

.c.o:		%.o : %.c
	@${CC} ${CFLAGS} -Imlx -c $< -o $@

all: 		$(NAME)

$(NAME):	$(OBJS)
	make re -C ./libft
	$(CC) $(OBJS) $(MLXFLAGS) -Llibft -lft -o $(NAME)


bonus:		$(OBJS_B)
	rm -f $(OBJS)
	make re -C ./libft
	$(CC) $(OBJS) $(MLXFLAGS) -Llibft -lft -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJS) $(OBJS_B)

fclean: 	clean
	make fclean -C ./libft
	rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re bonus