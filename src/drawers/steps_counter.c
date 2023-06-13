/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:09:06 by nesdebie          #+#    #+#             */
/*   Updated: 2023/06/13 13:51:29 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	print_step_count(t_game *game)
{
	ft_putstr_fd("Steps : ", 1);
	ft_putnbr_fd(game->player.spr.step, 1);
	ft_putstr_fd("\n", 1);
	game->flag.step_cnt = 0;
}

void	draw_step_count(t_game *game)
{
	char	*str;
	int		mlx;

	str = ft_itoa(game->player.spr.step);
	if (!str)
		close_game(game);
	if (game->flag.step_cnt)
		print_step_count(game);
	ft_put_img64(game, game->tile.t_count.ptr, 0, 0);
	mlx = mlx_string_put(game->mlx, game->win, 26, 20, 0x000000, str);
	free (str);
	if (mlx)
		close_game(game);
}
