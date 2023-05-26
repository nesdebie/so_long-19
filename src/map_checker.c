/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:18:42 by nedebies          #+#    #+#             */
/*   Updated: 2023/05/26 17:03:31 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map_compo(char c)
{
	if (c == '0' || c == '1' || c == 'C')
		return (1);
	else if (c == 'E' || c == 'P' || c == 'X')  //BONUS ('X')
		return (1);
	return (0);
}

int	is_map_rectangle(t_game *game, int len2)
{
	int	len1;

	len1 = game->maps.cols + 1;
	if (len1 != len2)
		return (0);
	return (1);
}

int	is_map_walled(t_map maps)
{
	int	max_col;
	int	max_row;
	int	i;

	i = 0;
	max_col = maps.cols - 1;
	max_row = maps.rows - 1;
	while (i < maps.rows)
	{
		if (maps.coord[i][0] != '1' || maps.coord[i][max_col] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < maps.cols)
	{
		if (maps.coord[0][i] != '1' || maps.coord[max_row][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
