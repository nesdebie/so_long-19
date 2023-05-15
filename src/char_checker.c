/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:06:05 by nedebies          #+#    #+#             */
/*   Updated: 2023/05/15 13:08:54 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int pathchecker(t_game *game, size_t xy, size_t prev_xy)
{
	size_t	i;
	size_t	j;

	i = xy / game->maps.cols;
	j = xy % game->maps.cols;
	if (game->maps.coord[i][j] != '1' && game->maps.coord[i][j] != 'E')
	{
		if (prev_xy != 0 && game->maps.coord[i][j] == 'P')
			return (1);
		if (game->maps.coord[i - 1][j] && (i - 1) * j != prev_xy && i - 1 > 0)
			return(pathchecker(game, (i - 1) * j, xy));
		if (game->maps.coord[i + 1][j] && (i + 1) * j != prev_xy && i + 1 < (size_t)game->maps.cols)
			return(pathchecker(game, (i + 1) * j, xy));
		if (game->maps.coord[i][j - 1] && i * (j - 1) != prev_xy && j - 1 > 0)
			return(pathchecker(game, i * (j - 1), xy));
		if (game->maps.coord[i][j + 1] && i * (j + 1) != prev_xy && j + 1 < (size_t)game->maps.rows)
			return(pathchecker(game, i  * (j + 1), xy));
	}
	return (pathchecker(game, prev_xy, xy));
}

#include <stdio.h>

static int	is_reachable(t_game *game, int nb, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	printf("%i\n", nb);
	while (game->maps.coord[i][j] && nb != 0)
	{
		printf("ici\n");
		j = 0;
		while (game->maps.coord[i][j] && nb != 0)
		{
			printf("ici2\n");
			if (game->maps.coord[i][j] == c)
			{
				printf("ici3\n");
				nb--;
				if (pathchecker(game, i * j, 0) && c == 'E')
					return (1);
				if (!pathchecker(game, i * j, 0))
					return (0);
			}
			j++;
		}
		i++;
	}
	printf("%i\n", nb);
	if (nb == 0)
		return (1);
	return (0);
}

static void	init_compo_cnt(t_game *game)
{
	game->maps.cnt.player = 0;
	game->maps.cnt.exit = 0;
	game->maps.cnt.collectible = 0;
}

static void	check_compo_cnt(t_game *game)
{
	if (game->maps.cnt.player < 1)
		ft_error("One player is required.");
	if (game->maps.cnt.player > 1)
		ft_error("Too many players (max. 1).");
	if (game->maps.cnt.collectible < 1)
		ft_error("One collectible is required.");
	if (!is_reachable(game, game->maps.cnt.collectible, 'C'))
		ft_error("All collectibles are not reachable.");
	if (game->maps.cnt.exit < 1)
		ft_error("One exit is required.");
	if (!is_reachable(game, game->maps.cnt.exit, 'E'))
		ft_error("Exit not reachable.");
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

	init_compo_cnt(game);
	i = 0;
	while (i < game->maps.rows)
	{
		j = 0;
		while (j < game->maps.cols)
		{
			get_compo_coord2(game, i, j);
			j++;
		}
		i++;
	}
	check_compo_cnt(game);
}
