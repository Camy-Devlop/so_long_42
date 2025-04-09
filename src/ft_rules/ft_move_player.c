/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:43:10 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/09 22:57:12 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_move_player(t_window win, t_coord *c_player, t_player p, t_card card)
{
	if (p->move)
	{
		ft_draw_asset(win, UP1, c_player->x, c_player->y);
		p->move = false;
	}
	else
	{
		ft_draw_asset(win, UP2, c_player->x, c_player->y);
		p->move = true;
	}
}
