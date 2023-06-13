/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:59:47 by nesdebie          #+#    #+#             */
/*   Updated: 2023/06/13 15:03:23 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		close_game(game);
	else if (!game->flag.held_keys)
	{
		if (key_code == KEY_W)
			ft_move(game, &(game->player.spr), UP);
		else if (key_code == KEY_A)
			ft_move(game, &(game->player.spr), LEFT);
		else if (key_code == KEY_S)
			ft_move(game, &(game->player.spr), DOWN);
		else if (key_code == KEY_D)
			ft_move(game, &(game->player.spr), RIGHT);
	}
	return (0);
}

static int	so_long(t_game *game)
{
	draw_map(game);
	draw_collect(game);
	if (game->maps.cnt.collectible == game->player.item)
		game->flag.got_all = 1;
	check_event_exit(game);
	draw_sprites(game);
	draw_step_count(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		ft_error("No argument (min. 1)");
	if (argc > 2)
		ft_error("Too many arguments (max. 1)");
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		ft_error("Not a '<name>.ber' file.");
	game.collec.clst = NULL;
	file_read(&game, argv[1]);
	init_game(&game);
	mlx_hook(game.win, KEYBOARD_CODE, 0, &deal_key, &game);
	mlx_hook(game.win, RED_CROSS, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &so_long, &game);
	mlx_loop(game.mlx);
	return (0);
}
