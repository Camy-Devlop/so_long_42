/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:05:34 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/11 20:52:45 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_move(t_window win, t_coord **c_player, t_player *p, t_card *card)
{
	(void)p;
	(void)c_player;
	(void)card;
	*c_player = win->room->p->coord;
	*card = win->room->card;
	*p = win->room->p;
}

bool	ft_move_up(t_window win)
{
	t_coord		*c_player;
	t_player	p;
	t_card		card;

	c_player = NULL;
	p = NULL;
	card = NULL;
	(void)p;
	(void)c_player;
	(void)card;
	init_move(win, &c_player, &p, &card);
	if (card->map[c_player->y - 1][c_player->x] == '1')
		return (c_player = NULL, card = NULL, p = NULL, false);
	if (card->map[c_player->y - 1][c_player->x] == 'C')
	{
		p->bag.nb++;
		ft_draw_asset(win, BG, c_player->x, c_player->y);
		c_player->y--;
		ft_move_player(win, c_player, p, UP1);
		card->map[c_player->y][c_player->x] = '0';
		return (c_player = NULL, card = NULL, p = NULL, true);
	}
	if (card->map[c_player->y - 1][c_player->x] == '0')
	{
		ft_draw_asset(win, BG, c_player->x, c_player->y);
		c_player->y--;
		ft_move_player(win, c_player, p, UP1);
		return (c_player = NULL, card = NULL, p = NULL, true);
	}
	return (false);
}
