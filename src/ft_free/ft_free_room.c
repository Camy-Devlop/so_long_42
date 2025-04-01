/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:02:28 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/01 13:07:06 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_free_room(t_game_room  room)
{
	if (!room)
		return ;
	if (room->card)
		ft_free_t_card(room->card, room->card->size.height - 1);
	if (room->p)
		ft_free_player(room->p);
	free(room->asset);
	room->asset = NULL;
	free(room);
	room = NULL;
}
