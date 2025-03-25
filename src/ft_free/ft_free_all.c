/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:05:29 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/25 10:37:37 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void ft_free_t_game_room(t_window win)
{
	int	i;

	if (!win->room)
		return ;
	if (win->room->card)
		ft_free_t_card(win->room->card, win->room->card->size.height - 1);
	if (win->room->p)
		ft_free_player(win->room->p);
	i = 0;
	while(win->room->asset[i])
	{
		mlx_destroy_image(win->mlx, win->room->asset[i++]);
	}
	free(win->room);
	win->room = NULL;
}

void ft_free_all(t_window win)
{
	if (win->title)
		free(win->title);
	win->title = NULL;
	ft_printf("title free");
	if (win->room)
		ft_free_t_game_room(win);
	ft_printf("room free");
	win->room = NULL;
	if (win->img)
		mlx_destroy_image(win->mlx, win->img);
	win->img = NULL;
	ft_free_t_window(win);
	win = NULL;
	ft_printf("total free");
}
