/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:56:57 by nedebies          #+#    #+#             */
/*   Updated: 2023/06/02 14:23:19 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(char *errmsg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(errmsg, 2);
	exit(EXIT_SUCCESS);
}

static void	ft_free_coll(t_clst **coll)
{
	t_clst	*tmp;

	if (!coll)
		return ;
	tmp = *coll;
	while (tmp)
	{
		*coll = tmp;
		tmp = tmp->next;
		free(*coll);
	}
	*coll = NULL;
}

int	close_game(t_game *game)
{
	ft_free_coll(&game->collec.clst);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
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
		close_game(game);
	}
	if (game->maps.coord[y][x] == 'X')
	{
		ft_putendl_fd("YOU DIED.", 1);
		close_game(game);
	}
}
