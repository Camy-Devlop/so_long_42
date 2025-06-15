/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_traking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 02:32:49 by isadbaib          #+#    #+#             */
/*   Updated: 2025/06/15 16:42:13 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	back_traking(t_card c, t_coord now, bool t);

static bool	ft_search(t_card c, t_coord now, bool t)
{
	if (c->map[now.y - 1][now.x] != '1' && c->map[now.y - 1][now.x] != 'D')
	{
		return (t = back_traking(c, (t_coord){now.x, now.y - 1}, false), t);
	}
	else if (c->map[now.y][now.x + 1] != '1'
			&& c->map[now.y][now.x + 1] != 'D')
	{
		return (t = back_traking(c, (t_coord){now.x + 1, now.y}, false), t);
	}
	else if (c->map[now.y][now.x - 1] != '1'
			&& c->map[now.y][now.x - 1] != 'D')
	{
		return (t = back_traking(c, (t_coord){now.x - 1, now.y}, false), t);
	}
	else if (c->map[now.y + 1][now.x] != '1'
			&& c->map[now.y + 1][now.x] != 'D')
	{
		return (t = back_traking(c, (t_coord){now.x, now.y + 1}, false), t);
	}
	else
		return (false);
}

bool	back_traking(t_card c, t_coord now, bool t)
{
	int	i;

	if (1 > now.y || now.y > c->size.height - 1
		|| 1 > now.x || now.x > c->size.width - 1)
		return (false);
	if (c->map[now.y][now.x] == 'E')
		return (true);
	c->map[now.y][now.x] = 'D';
	i = 0;
	while (i < 4)
	{
		if (ft_search(c, now, t))
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
