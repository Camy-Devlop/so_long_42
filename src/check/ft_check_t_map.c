/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_t_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:45:56 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/16 02:23:51 by isadbaib         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	ft_check_card_map(char **map, t_size_card *s)
{
	size_t i;
	size_t j;
	if (!map || !s)
		return (false);
	i = 0;
	while (i < s->width)
	{
		if (map[0][i] != '1' || map[s->height-1][i] != '1')
			return (false);
	
	}
	return (true);
}

bool	ft_check_size_t_map(t_map m)
{
	size_t	nb;
	t_map	t;

	if (!m)
		return (false);
	if (*(m->nb) < 3 && ft_strlen(m->line) < 3)
		return (ft_err_t_map(0), false);
	if ((long unsigned int)*(m->nb) == ft_strlen(m->line))
		return (ft_err_t_map(1), false);
	if (42 < (long unsigned int)*(m->nb) && 77 < ft_strlen(m->line))
		return (ft_err_t_map(1), false);
	t = m;
	nb = ft_strlen(m->line);
	while (t)
	{
		if (nb != ft_strlen(t->line))
			return (t = NULL, ft_err_t_map(2), false);
		t = t->next;
	}
	return (true);
}
