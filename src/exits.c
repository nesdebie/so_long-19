/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:56:57 by nedebies          #+#    #+#             */
/*   Updated: 2023/05/26 16:55:46 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(char *errmsg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(errmsg, 2);
	exit(1);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	check_event_exit(t_game *game)
{
	int	x;
	int	y;

	x = game->player.spr.x;
	y = game->player.spr.y;
	if (game->maps.coord[y][x] == 'E'
		&& game->flag.got_all && !game->flag.player_walk)
	{
		ft_putendl_fd("Good job !", 1);
		exit(EXIT_SUCCESS);
	}
	if (game->maps.coord[y][x] == 'X')
	{
		ft_putendl_fd("YOU DIED.", 1);
		exit(EXIT_FAILURE);
	}
}
