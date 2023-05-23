/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:16:25 by nedebies          #+#    #+#             */
/*   Updated: 2023/05/23 12:20:36 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# define NO_MOVE	0
# define DOWN		1
# define LEFT		2
# define UP			3
# define RIGHT		4

# define KEY_ESC	53

# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2

# define PLAYER_SPEED	4

# define TILE_SIZE		64

typedef struct s_flags
{
	int		got_all;
	int		held_keys;
	int		player_walk;
	int		step_cnt;
}			t_flags;

typedef struct s_compo
{
	int		player;
	int		exit;
	int		collectible;
}			t_compo;

typedef struct s_check
{
	int				x;
	int				y;
	struct s_check	*next;
}			t_check;

typedef struct s_img
{
	void	*ptr;
	int		h;
	int		w;
}			t_img;

typedef struct s_coord
{
	int		x;
	int		y;
}			t_coord;

typedef struct s_clst
{
	t_coord			coord;
	int				istouch;
	struct s_clst	*next;
}					t_clst;

typedef struct s_tile
{
	t_img	t0;
	t_img	t1;
	t_img	te;
	t_img	t_count;
	t_img	t_blocked;
	t_img	tx;
}			t_tile;

typedef struct s_coll
{
	t_img	coll;
	t_clst	*clst;
}			t_coll;

typedef struct s_spr
{
	t_img	imgx[5][3];
	int		frame;
	int		frame_max;
	int		step;
	int		x;
	int		y;
	int		x0;
	int		y0;
	int		i;
	int		dir;
	int		move;
}			t_spr;

typedef struct s_player
{
	t_spr	spr;
	int		step;
	int		item;
}			t_player;

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**coord;
	char	*file;
	t_compo	cnt;
}			t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img64;
	t_tile		tile;
	t_coll		collec;
	t_player	player;
	t_coord		dir2coord[5];
	t_map		maps;
	t_check		*check;
	t_flags		flag;
}				t_game;

void	ft_error(char *msg);
int		close_game(t_game *game);
void	check_event_exit(t_game *game);

int		check_map_compo(char c);
int		is_map_rectangle(t_game *game, int len2);
int		is_map_walled(t_map maps);
void	get_compo_coord(t_game *game);
void	file_read(t_game *game, char *filename);

void	*ft_xpm_to_img(t_game *game, char *str);
void	ft_put_img64(t_game *game, void *img_ptr, int x, int y);
void	ft_put_img(t_game *game, void *img_ptr, int x, int y);

void	init_game(t_game *game);
void	init_collec(t_game *game);
void	init_img(t_game *game);

void	ft_move(t_game *game, t_spr *sprite, int i);

t_clst	*clst_new(int x, int y);
void	clst_add_back(t_clst **lst, t_clst *new);

void	draw_collect(t_game *game);
void	draw_map(t_game *game);
void	draw_player(t_game *game);
void	draw_step_count(t_game *game);
void	draw_sprites(t_game *game);

void	ft_checkclear(t_check **lst);
int		check_path(t_game *game, int y, int x, int *exit);

#endif