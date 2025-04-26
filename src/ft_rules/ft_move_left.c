/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:04:04 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/26 20:28:06 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	update_image_left(t_card c, t_coord *c_p, t_player p, t_window win)
{
	ft_draw_asset(win, BG, c_p->x, c_p->y);
	if (c->map[c_p->y][c_p->x] == 'E')
		ft_draw_asset(win, DOOR, c_p->x, c_p->y);
	c_p->x--;
	ft_move_player(win, c_p, p, LEFT1);
}

bool	ft_move_left(t_window win)
{
	t_coord		*c_player;
	t_player	p;
	t_card		card;

	init_move(win, &c_player, &p, &card);
	if (card->map[c_player->y][c_player->x - 1] == 'C')
	{
		p->bag.nb--;
		update_image_left(card, c_player, p, win);
		card->map[c_player->y][c_player->x] = '0';
		return (c_player = NULL, card = NULL, p = NULL, true);
	}
	if (card->map[c_player->y][c_player->x - 1] == '0')
	{
		update_image_left(card, c_player, p, win);
		return (c_player = NULL, card = NULL, p = NULL, true);
	}
	if (card->map[c_player->y][c_player->x - 1] == 'E')
	{
		update_image_left(card, c_player, p, win);
		c_player = NULL;
		if (p->bag.nb == 0)
			return (card = NULL, p = NULL, ft_close(win), true);
	}
	return (c_player = NULL, card = NULL, p = NULL, false);
}
