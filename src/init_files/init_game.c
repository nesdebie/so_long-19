/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:02:33 by nesdebie          #+#    #+#             */
/*   Updated: 2023/06/13 13:44:15 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	init_dir(t_game *game)
{
	game->dir2coord[NO_MOVE] = (t_coord){0, 0};
	game->dir2coord[UP] = (t_coord){0, -1};
	game->dir2coord[DOWN] = (t_coord){0, 1};
	game->dir2coord[LEFT] = (t_coord){-1, 0};
	game->dir2coord[RIGHT] = (t_coord){1, 0};
}

static void	init_window(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("mlx_init() failed.");
	width = game->maps.cols * TILE_SIZE;
	height = game->maps.rows * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
		ft_error("mlx_new_window() failed.");
}

static void	init_player(t_game *game)
{
	game->player.step = 0;
	game->player.item = 0;
	game->player.spr.step = 0;
	game->player.spr.frame = 0;
	game->player.spr.frame_max = 3;
	game->player.spr.i = 0;
	game->player.spr.dir = DOWN;
	game->player.spr.move = 1;
}

static void	init_flag(t_game *game)
{
	game->flag.got_all = 0;
	game->flag.held_keys = 0;
	game->flag.player_walk = 0;
	game->flag.step_cnt = 0;
}

void	init_game(t_game *game)
{
	init_window(game);
	init_dir(game);
	init_img(game);
	init_player(game);
	init_flag(game);
}
