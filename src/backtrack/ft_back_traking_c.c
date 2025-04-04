/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_traking_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:30:48 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/04 23:41:47 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool		back_traking_c(t_card c, t_bag *bag, t_coord now, bool t);

size_t	nb_collector(t_card c)
{
	size_t	i;
	size_t	j;
	size_t	collector;

	if (!c)
		return (0);
	if (!c->map)
		return (0);
	if (c->size.height < 3 || c->size.width < 3)
		return (0);
	i = 0;
	collector = 0;
	while (i < c->size.height)
	{
		j = 0;
		while (j < c->size.width)
		{
			if (c->map[i][j] == 'C')
				collector++;
			j++;
		}
		i++;
	}
	return (collector);
}

static bool	ft_search(t_card c, t_bag *bag, t_coord now, bool t)
{
	if (c->map[now.y - 1][now.x] != '1' && c->map[now.y - 1][now.x] != 'D')
	{
		return (t = back_traking_c(c, bag, (t_coord){now.x, now.y - 1}, false),
			t);
	}
	else if (c->map[now.y][now.x + 1] != '1' && c->map[now.y][now.x + 1] != 'D')
	{
		return (t = back_traking_c(c, bag, (t_coord){now.x + 1, now.y}, false),
			t);
	}
	else if (c->map[now.y][now.x - 1] != '1' && c->map[now.y][now.x - 1] != 'D')
	{
		return (t = back_traking_c(c, bag, (t_coord){now.x - 1, now.y}, false),
			t);
	}
	else if (c->map[now.y + 1][now.x] != '1' && c->map[now.y + 1][now.x] != 'D')
	{
		return (t = back_traking_c(c, bag, (t_coord){now.x, now.y + 1}, false),
			t);
	}
	else
		return (false);
}

bool	back_traking_c(t_card c, t_bag *bag, t_coord now, bool t)
{
	int	i;

	if (bag->nb == 0)
		return (false);
	if (1 > now.y || now.y > c->size.height - 1 || 1 > now.x
		|| now.x > c->size.width - 1)
		return (false);
	if (bag->nb == bag->nb_collected)
		return (true);
	if (c->map[now.y][now.x] == 'C')
		bag->nb_collected++;
	c->map[now.y][now.x] = 'D';
	i = 0;
	while (i < 4)
	{
		if (ft_search(c, bag, now, t))
		{
			t = true;
			break ;
		}
		i++;
	}
	if (t)
		return (t);
	return (false);
}
