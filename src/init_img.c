/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:51:32 by nedebies          #+#    #+#             */
/*   Updated: 2023/05/26 17:03:05 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_img(t_game *game)
{
	t_spr	*ply;

	game->tile.t0.ptr = ft_xpm_to_img(game, "./img/ground.xpm");
	game->tile.t1.ptr = ft_xpm_to_img(game, "./img/wall.xpm");
	game->tile.te.ptr = ft_xpm_to_img(game, "./img/collectible.xpm");
	game->tile.t_count.ptr = ft_xpm_to_img(game, "./img/wooden_sign.xpm"); //BONUS
	game->tile.t_blocked.ptr = ft_xpm_to_img(game, "./img/stone.xpm");
	game->tile.tx.ptr = ft_xpm_to_img(game, "./img/enemy.xpm"); //BONUS
	ply = &(game->player.spr);
	ply->imgx[UP][0].ptr = ft_xpm_to_img(game, "./img/up0.xpm");
	ply->imgx[UP][1].ptr = ft_xpm_to_img(game, "./img/up1.xpm"); //BONUS
	ply->imgx[UP][2].ptr = ft_xpm_to_img(game, "./img/up2.xpm"); //BONUS
	ply->imgx[DOWN][0].ptr = ft_xpm_to_img(game, "./img/down0.xpm");
	ply->imgx[DOWN][1].ptr = ft_xpm_to_img(game, "./img/down1.xpm"); //BONUS
	ply->imgx[DOWN][2].ptr = ft_xpm_to_img(game, "./img/down2.xpm"); //BONUS
	ply->imgx[LEFT][0].ptr = ft_xpm_to_img(game, "./img/left0.xpm");
	ply->imgx[LEFT][1].ptr = ft_xpm_to_img(game, "./img/left1.xpm"); //BONUS
	ply->imgx[LEFT][2].ptr = ft_xpm_to_img(game, "./img/left2.xpm"); //BONUS
	ply->imgx[RIGHT][0].ptr = ft_xpm_to_img(game, "./img/right0.xpm");
	ply->imgx[RIGHT][1].ptr = ft_xpm_to_img(game, "./img/right1.xpm"); //BONUS
	ply->imgx[RIGHT][2].ptr = ft_xpm_to_img(game, "./img/right2.xpm"); //BONUS
	game->collec.coll.ptr = ft_xpm_to_img(game, "./img/cerbyllin.xpm");
}
