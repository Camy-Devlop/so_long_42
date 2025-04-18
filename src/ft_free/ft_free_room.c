/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:02:28 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/18 22:47:58 by isadbaib         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_free_room(t_game_room room)
{
	if (!room)
		return ;
	if (room->card)
		ft_free_t_card(room->card, room->card->size.height - 1);
	if (room->p)
		ft_free_player(room->p);
	if (room->asset)
		free(room->asset);
	room->asset = NULL;
	free(room);
	room = NULL;
}
