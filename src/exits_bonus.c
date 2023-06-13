/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:01:13 by nesdebie          #+#    #+#             */
/*   Updated: 2023/06/13 12:35:41 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_free_arr(char **arr, int j)
{
	if (j != -1)
	{
		while (j != 0)
			free(arr[--j]);
	}
	else
	{
		while (arr[j])
			j++;
		while (j != 0)
			free(arr[--j]);
	}
	free(arr);
	arr = NULL;
	return (NULL);
}

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
	if (game->collec.clst)
		ft_free_coll(&game->collec.clst);
	if (game->mlx && game->win)
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
