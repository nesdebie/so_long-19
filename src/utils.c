/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:01:06 by nedebies          #+#    #+#             */
/*   Updated: 2022/07/07 16:22:52 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_clst	*clst_new(int x, int y)
{
	t_clst	*new;

	new = (t_clst *)malloc(sizeof(t_clst));
	if (!new)
		return (NULL);
	new->coord.x = x;
	new->coord.y = y;
	new->istouch = 0;
	new->next = NULL;
	return (new);
}

static t_clst	*clst_last(t_clst *lst)
{
	t_clst	*curr;

	curr = lst;
	if (!lst)
		return (NULL);
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}

void	clst_add_back(t_clst **lst, t_clst *new)
{
	t_clst	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = clst_last(*lst);
	new->next = last->next;
	last->next = new;
}
