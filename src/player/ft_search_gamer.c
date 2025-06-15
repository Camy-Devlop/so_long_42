/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_gamer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:30:09 by isadbaib          #+#    #+#             */
/*   Updated: 2025/06/15 16:40:51 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static size_t	nb_player(t_card c)
{
	size_t	i;
	size_t	j;
	size_t	player;

	if (!c)
		return (0);
	if (!c->map)
		return (0);
	if (c->size.height < 3 || c->size.width < 3)
		return (0);
	i = 0;
	player = 0;
	while (i < c->size.height)
	{
		j = 0;
		while (j < c->size.width)
		{
			if (c->map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	return (player);
}

static t_coord	*ft_player_coord(t_card c)
{
	t_coord	*p;
	size_t	i;
	size_t	j;

	if (!c || !c->map || 1 != nb_player(c))
		return (NULL);
	p = ft_calloc(1, sizeof(t_coord));
	if (!p)
		return (ft_err_coord(0), NULL);
	i = 0;
	while (i < c->size.height)
	{
		j = 0;
		while (j < c->size.width)
		{
			if (c->map[i][j] == 'P')
				return (p->x = j, p->y = i, p);
			j++;
		}
		i++;
	}
	c = NULL;
	return (ft_err_player(0), ft_free_coord(p), p = NULL, NULL);
}

t_player	create_t_player(t_card c)
{
	t_coord		*coord;
	t_player	p;

	coord = ft_player_coord(c);
	if (!coord)
		return (NULL);
	if (1 > coord->y || coord->y > c->size.height - 1 || 1 > coord->x
		|| coord->x > c->size.width - 1)
		return (ft_free_coord(coord), ft_free_t_card(c, c->size.height - 1),
			NULL);
	p = ft_calloc(1, sizeof(struct s_player));
	if (!p)
		return (ft_free_coord(coord), ft_free_t_card(c, c->size.height - 1),
			NULL);
	p->coord = coord;
	coord = NULL;
	ft_free_t_card(c, c->size.height - 1);
	return (p);
}
