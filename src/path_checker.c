/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:16:46 by nesdebie          #+#    #+#             */
/*   Updated: 2023/05/23 12:21:53 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_checkclear(t_check **lst)
{
	t_check	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		*lst = tmp;
		tmp = tmp->next;
		free(*lst);
	}
	*lst = NULL;
}

static t_check	*ft_checknew(int x, int y)
{
	t_check	*new;

	new = (t_check *)malloc(sizeof(t_check));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->next = NULL;
	return (new);
}

static void	ft_checkadd_back(t_check **lst, t_check *new)
{
	t_check	*tmp;

	tmp = *lst;
	if (!*lst && new)
	{
		new->next = tmp;
		*lst = new;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static int	already_checked(t_check *check, int x, int y)
{
	t_check	*tmp;

	tmp = check;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_path(t_game *game, int y, int x, int *exit)
{
	if (!game->maps.coord[y][x])
		return (0);
	if (already_checked(game->check, x, y))
		return (0);
	if (game->maps.coord[y][x] == '1')
		return (0);
	if (game->maps.coord[y][x] == 'C')
		game->maps.cnt.collectible--;
	if (game->maps.coord[y][x] == 'E')
	{
		*exit = 1;
		return (0);
	}
	ft_checkadd_back(&game->check, ft_checknew(x, y));
	if (check_path(game, y + 1, x, exit))
		return (1);
	if (check_path(game, y - 1, x, exit))
		return (1);
	if (check_path(game, y, x + 1, exit))
		return (1);
	if (check_path(game, y, x - 1, exit))
		return (1);
	return (0);
}
