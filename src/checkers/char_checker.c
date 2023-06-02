/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:06:05 by nedebies          #+#    #+#             */
/*   Updated: 2023/06/02 14:41:48 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	init_compo_cnt(t_game *game)
{
	game->maps.cnt.player = 0;
	game->maps.cnt.exit = 0;
	game->maps.cnt.collectible = 0;
}

static void	check_compo_cnt(t_game *game, int x, int y)
{
	int	valid_exit;
	int	nb_collec;

	valid_exit = 0;
	nb_collec = game->maps.cnt.collectible;
	if (game->maps.cnt.player < 1)
		ft_error("One player is required.");
	if (game->maps.cnt.player > 1)
		ft_error("Too many players (max. 1).");
	if (game->maps.cnt.collectible < 1)
		ft_error("One collectible is required.");
	if (game->maps.cnt.exit < 1)
		ft_error("One exit is required.");
	if (game->maps.cnt.exit > 1)
		ft_error("Too many exits.");
	check_path(game, y, x, &valid_exit);
	ft_checkclear(&(game->check));
	if (!(valid_exit == 1 && game->maps.cnt.collectible == 0))
		ft_error("No valid path");
	game->maps.cnt.collectible = nb_collec;
}

static void	get_compo_coord2(t_game *game, int i, int j)
{
	if (game->maps.coord[i][j] == 'P')
	{
		game->player.spr.x = j;
		game->player.spr.x0 = j;
		game->player.spr.y = i;
		game->player.spr.y0 = i;
		game->maps.cnt.player++;
	}
	else if (game->maps.coord[i][j] == 'C')
	{
		game->maps.cnt.collectible++;
		clst_add_back(&(game->collec.clst), clst_new(j, i));
	}
	else if (game->maps.coord[i][j] == 'E')
		game->maps.cnt.exit++;
}

void	get_compo_coord(t_game *game)
{
	int	i;
	int	j;
	int	x_p;
	int	y_p;

	x_p = 0;
	y_p = 0;
	init_compo_cnt(game);
	i = 0;
	while (i < game->maps.rows)
	{
		j = 0;
		while (j < game->maps.cols)
		{
			if (game->maps.coord[i][j] == 'P')
			{
				x_p = j;
				y_p = i;
			}
			get_compo_coord2(game, i, j);
			j++;
		}
		i++;
	}
	check_compo_cnt(game, x_p, y_p);
}
