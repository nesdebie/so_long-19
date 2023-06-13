/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:06:21 by nesdebie          #+#    #+#             */
/*   Updated: 2023/06/13 12:34:38 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		ft_error("open() failed.");
	return (fd);
}

static void	count_max_rows_cols(t_game *game, int fd)
{
	int		tmp_cols;
	char	c;

	game->maps.rows = 0;
	game->maps.cols = 0;
	tmp_cols = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (game->maps.cols < tmp_cols)
			game->maps.cols = tmp_cols;
		if (c == '\n')
		{
			game->maps.rows++;
			tmp_cols = 0;
		}
		else
			tmp_cols++;
	}
}

static void	map_malloc(t_game *game, int fd)
{
	int	i;

	count_max_rows_cols(game, fd);
	game->maps.coord = (char **)malloc(sizeof(char *) * (game->maps.rows));
	if (!game->maps.coord)
		exit(0);
	i = 0;
	while (i < game->maps.rows)
	{
		game->maps.coord[i] = (char *)malloc(sizeof(char) * (game->maps.cols));
		if (!game->maps.coord[i])
		{
			ft_free_arr(game->maps.coord, i);
			exit(0);
		}
		i++;
	}
}

static void	map_load(t_game *game, char *filename)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open_file(filename);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (is_map_rectangle(game, ft_strlen(line)) == 0)
			ft_error("The map is not rectangular.");
		j = -1;
		while (++j < game->maps.cols)
		{
			if (check_map_compo(line[j]) == 1)
				game->maps.coord[i][j] = line[j];
			else
				ft_error("An invalid character has been found.");
		}
		free(line);
		i++;
	}
	free(line);
	close(fd);
}

void	file_read(t_game *game, char *filename)
{
	int		fd;

	fd = open_file(filename);
	map_malloc(game, fd);
	close(fd);
	map_load(game, filename);
	if (is_map_walled(game->maps) == 0)
		ft_error("The map is not surrounded by walls.");
	get_compo_coord(game);
}
