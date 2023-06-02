/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_drawer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:03:53 by nedebies          #+#    #+#             */
/*   Updated: 2023/06/02 14:47:17 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_collect(t_game *game)
{
	int		x;
	int		y;
	t_clst	*lst;

	x = game->player.spr.x;
	y = game->player.spr.y;
	lst = game->collec.clst;
	while (lst)
	{
		if (!lst->istouch)
		{
			if (lst->coord.x == x && lst->coord.y == y)
			{
				lst->istouch = 1;
				game->player.item++;
			}
			ft_put_img64(game, game->collec.coll.ptr,
				lst->coord.x, lst->coord.y);
		}
		lst = lst->next;
	}
}

void	draw_sprites(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->maps.rows)
	{
		j = 0;
		while (j < game->maps.cols)
		{
			if (game->player.spr.x == j && game->player.spr.y == i)
				draw_player(game);
			j++;
		}
		i++;
	}
}

static t_img	*get_player_sprite(t_game *game, int dir)
{
	t_img	*spr;

	if (game->player.spr.frame == 1)
		spr = &(game->player.spr.imgx[dir][1]);
	else if (game->player.spr.frame == 3)
		spr = &(game->player.spr.imgx[dir][2]);
	else
		spr = &(game->player.spr.imgx[dir][0]);
	return (spr);
}

static void	ft_walk(t_game *game, t_spr *player, t_img *sprite, int dir)
{
	int	x;
	int	y;

	game->flag.held_keys = 1;
	x = (player->x0 * TILE_SIZE)
		+ (game->dir2coord[dir].x * player->i * player->move);
	y = ((player->y0 - 1) * TILE_SIZE)
		+ (game->dir2coord[dir].y * player->i * player->move);
	ft_put_img(game, sprite->ptr, x, y);
	player->i += PLAYER_SPEED;
	if (player->i >= 64)
	{
		player->i = 0;
		game->player.spr.frame++;
		game->flag.held_keys = 0;
		game->flag.player_walk = 0;
	}
}

void	draw_player(t_game *game)
{
	int		dir;
	t_spr	*player;
	t_img	*sprite;

	dir = game->player.spr.dir;
	player = &(game->player.spr);
	sprite = get_player_sprite(game, dir);
	if (game->flag.player_walk)
		ft_walk(game, player, sprite, dir);
	else
		ft_put_img64(game, sprite->ptr, player->x, player->y - 1);
}
