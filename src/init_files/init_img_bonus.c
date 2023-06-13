/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:03:04 by nesdebie          #+#    #+#             */
/*   Updated: 2023/06/03 18:03:14 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_img(t_game *game)
{
	t_spr	*ply;

	game->tile.t0.ptr = ft_xpm_to_img(game, "./img/ground.xpm");
	game->tile.t1.ptr = ft_xpm_to_img(game, "./img/wall.xpm");
	game->tile.te.ptr = ft_xpm_to_img(game, "./img/exit.xpm");
	game->tile.t_count.ptr = ft_xpm_to_img(game, "./img/wooden_sign.xpm");
	game->tile.t_blocked.ptr = ft_xpm_to_img(game, "./img/stone.xpm");
	game->tile.tx.ptr = ft_xpm_to_img(game, "./img/enemy.xpm");
	game->collec.coll.ptr = ft_xpm_to_img(game, "./img/collectible.xpm");
	ply = &(game->player.spr);
	ply->imgx[UP][0].ptr = ft_xpm_to_img(game, "./img/up0.xpm");
	ply->imgx[UP][1].ptr = ft_xpm_to_img(game, "./img/up1.xpm");
	ply->imgx[UP][2].ptr = ft_xpm_to_img(game, "./img/up2.xpm");
	ply->imgx[DOWN][0].ptr = ft_xpm_to_img(game, "./img/down0.xpm");
	ply->imgx[DOWN][1].ptr = ft_xpm_to_img(game, "./img/down1.xpm");
	ply->imgx[DOWN][2].ptr = ft_xpm_to_img(game, "./img/down2.xpm");
	ply->imgx[LEFT][0].ptr = ft_xpm_to_img(game, "./img/left0.xpm");
	ply->imgx[LEFT][1].ptr = ft_xpm_to_img(game, "./img/left1.xpm");
	ply->imgx[LEFT][2].ptr = ft_xpm_to_img(game, "./img/left2.xpm");
	ply->imgx[RIGHT][0].ptr = ft_xpm_to_img(game, "./img/right0.xpm");
	ply->imgx[RIGHT][1].ptr = ft_xpm_to_img(game, "./img/right1.xpm");
	ply->imgx[RIGHT][2].ptr = ft_xpm_to_img(game, "./img/right2.xpm");
}
