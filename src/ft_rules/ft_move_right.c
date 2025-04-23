/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:07:19 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/20 16:27:16 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	ft_move_right(t_window win)
{
	t_coord		*c_player;
	t_player	p;
	t_card		card;

	init_move(win, &c_player, &p, &card);
	if (card->map[c_player->y][c_player->x + 1] == '1')
		return (c_player = NULL, card = NULL, p = NULL, false);
	if (card->map[c_player->y][c_player->x + 1] == 'C')
	{
		p->bag.nb++;
		ft_draw_asset(win, BG, c_player->x, c_player->y);
		c_player->x++;
		ft_move_player(win, c_player, p, RIGHT1);
		card->map[c_player->y][c_player->x] = '0';
		return (c_player = NULL, card = NULL, p = NULL, true);
	}
	if (card->map[c_player->y][c_player->x + 1] == '0')
	{
		ft_draw_asset(win, BG, c_player->x, c_player->y);
		c_player->x++;
		ft_move_player(win, c_player, p, RIGHT1);
		return (c_player = NULL, card = NULL, p = NULL, true);
	}
	return (false);
}
