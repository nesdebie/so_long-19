/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:56:57 by nedebies          #+#    #+#             */
/*   Updated: 2022/07/07 16:19:30 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(char *errmsg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(errmsg, 2);
	ft_putstr_fd("\n", 2);
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
		ft_putstr_fd("Good job !\n", 1);
		exit(EXIT_SUCCESS);
	}
	if (game->maps.coord[y][x] == 'X')
	{
		ft_putstr_fd("YOU DIED.\n", 1);
		exit(EXIT_FAILURE);
	}
}
