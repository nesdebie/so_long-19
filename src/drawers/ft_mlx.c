/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:07:04 by nesdebie          #+#    #+#             */
/*   Updated: 2023/06/13 13:42:08 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	*ft_xpm_to_img(t_game *game, char *str)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, str,
			&(game->img64.w), &(game->img64.h));
	if (!img)
	{
		ft_free_arr(game->maps.coord, -1);
		ft_error("mlx_xpm_file_to_image failed.");
	}
	return (img);
}

void	ft_put_img64(t_game *game, void *img_ptr, int x, int y)
{
	int	mlx;

	mlx = mlx_put_image_to_window(game->mlx, game->win,
			img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	if (!mlx)
		close_game(game);
}

void	ft_put_img(t_game *game, void *img_ptr, int x, int y)
{
	int	mlx;

	mlx = mlx_put_image_to_window(game->mlx, game->win, img_ptr, x, y);
	if (!mlx)
		close_game(game);
}
