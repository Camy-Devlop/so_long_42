/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:57:56 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/04 23:36:43 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	ft_move_up(t_window win)
{
	t_coord		c_player;
	t_player	p;
	t_card		card;

	c_player = win->room->p->coord;
	card = win->room->card;
	p = win->room->p;
	if (card->map[c_player->y - 1][c_player->x] == '1')
		return (c_player = NULL, card = NULL, p = NULL, false);
	if (card->map[c_player->y - 1][c_player->x] == 'C')
	{
		p.bag++;
		return (c_player = NULL, card = NULL, p = NULL, true);
	}
}

bool	ft_move_down(t_window win)
{
}

bool	ft_move_left(t_window win)
{
}

bool	ft_move_right(t_window win)
{
}
