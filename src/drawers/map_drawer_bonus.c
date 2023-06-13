/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:08:01 by nesdebie          #+#    #+#             */
/*   Updated: 2023/06/13 11:48:58 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	draw_map2(t_game *game, int i, int j)
{
	if (game->maps.coord[i][j] == '1')
		ft_put_img64(game, game->tile.t1.ptr, j, i);
	else if (game->maps.coord[i][j] == 'X')
	{
		ft_put_img64(game, game->tile.t0.ptr, j, i);
		ft_put_img64(game, game->tile.tx.ptr, j, i);
	}
	else if (game->maps.coord[i][j] == 'E')
	{
		if (game->flag.got_all)
		{
			ft_put_img64(game, game->tile.t0.ptr, j, i);
			ft_put_img64(game, game->tile.te.ptr, j, i);
		}
		else
		{
			ft_put_img64(game, game->tile.t0.ptr, j, i);
			ft_put_img64(game, game->tile.t_blocked.ptr, j, i);
		}
	}
	else
		ft_put_img64(game, game->tile.t0.ptr, j, i);
}

void	draw_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->maps.rows)
	{
		j = 0;
		while (j < game->maps.cols)
		{
			draw_map2(game, i, j);
			j++;
		}
		i++;
	}
}
