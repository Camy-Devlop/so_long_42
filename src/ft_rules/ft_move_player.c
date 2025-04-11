/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:43:10 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/11 19:50:24 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_move_player(t_window win, t_coord *c_player, t_player p, int move)
{
	if (p->move)
	{
		ft_draw_asset(win, move, c_player->x, c_player->y);
		p->move = false;
	}
	else
	{
		ft_draw_asset(win, move + 1, c_player->x, c_player->y);
		p->move = true;
	}
}
