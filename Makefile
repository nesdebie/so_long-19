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

SRCS_B = 	src/main.c \
			src/checkers/char_checker.c \
			src/checkers/path_checker_bonus.c \
			src/drawers/sprites_drawer.c \
			src/utils.c \
			src/exits_bonus.c \
			src/drawers/steps_counter.c \
			src/drawers/ft_mlx.c \
			src/init_files/init_game.c \
			src/init_files/init_img_bonus.c \
			src/checkers/map_checker_bonus.c \
			src/checkers/map_reader.c \
			src/drawers/map_drawer_bonus.c \
			src/drawers/ft_move.c

SRCS_C =	src/exits.c \
			src/init_files/init_img.c \
			src/checkers/map_checker.c \
			src/checkers/path_checker.c \
			src/drawers/map_drawer.c

OBJS 	= $(SRCS:.c=.o)

OBJS_B 	= $(SRCS_B:.c=.o)

OBJS_C 	= $(SRCS_C:.c=.o)

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -Lmlx

.c.o:		%.o : %.c
	@${CC} ${CFLAGS} -Imlx -c $< -o $@

all: 		$(NAME)

$(NAME):	$(OBJS)
	make -C ./libft
	make -C ./mlx
	$(CC) $(OBJS) $(MLXFLAGS) -Llibft -lft -o $(NAME)


bonus:		$(OBJS_B)
	rm -f $(OBJS_C)
	make re -C ./libft
	make -C ./mlx
	$(CC) $(OBJS_B) $(MLXFLAGS) -Llibft -lft -o $(NAME)

clean:
	make clean -C ./libft
	make clean -C ./mlx
	rm -f $(OBJS) $(OBJS_B)

fclean: 	clean
	make fclean -C ./libft
	rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re bonus