/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:53:06 by nesdebie          #+#    #+#             */
/*   Updated: 2023/05/15 10:47:25 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	j = 0;
	i = ft_strlen(s1);
	result = (char *)malloc((i + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (ft_free(s1, 0));
	while (s1[j])
	{
		result[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i])
	{
		result[j] = s2[i];
		i++;
		j++;
	}
	result[j] = 0;
	free(s1);
	return (result);
}
