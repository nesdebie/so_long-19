/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:56:21 by nedebies          #+#    #+#             */
/*   Updated: 2023/05/26 16:56:04 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_wall(t_game *game, t_spr *sprite, int dir)
{
	int		x;
	int		y;
	char	c;

	x = game->dir2coord[dir].x;
	y = game->dir2coord[dir].y;
	c = game->maps.coord[sprite->y + y][sprite->x + x];
	if (c == '1')
	{
		ft_putendl_fd("*BONK*", 1);
		return (1);
	}
	else if (c == 'E' && !game->flag.got_all)
	{
		ft_putendl_fd("*BONK*", 1);
		return (1);
	}
	return (0);
}

void	ft_move(t_game *game, t_spr *sprite, int i)
{
	int	dir;

	dir = i;
	sprite->x0 = sprite->x;
	sprite->y0 = sprite->y;
	sprite->dir = dir;
	if (sprite->frame > sprite->frame_max)
		sprite->frame = 0;
	sprite->frame++;
	if (!is_wall(game, sprite, dir))
	{
		sprite->move = 1;
		sprite->x += game->dir2coord[dir].x;
		sprite->y += game->dir2coord[dir].y;
		sprite->step++;
		if (sprite == &(game->player.spr))
			game->flag.step_cnt = 1;
	}
	else
		sprite->move = 0;
	game->flag.player_walk = 1;
}
