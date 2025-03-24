/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:05:29 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/24 14:06:01 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void ft_free_t_game_room(t_game_room room)
{
	int	i;

	if (!room)
		return ;
	if (room->card)
		ft_free_t_card(room->card);
	if (room->p)
		ft_free_gamer(room->p);
	i = 0;
	while(room->asset[i])
		mlx_destroy_image(room->asset[i++]);
	free(room);
	room = NULL;
}

void ft_free_all(t_window win)
{
	if (win->title)
		free(win->title);
	win->title = NULL;
	ft_printf("title free");
	if (win->room)
		ft_free_t_game_room(win->room);
	ft_printf("room free");
	win->romm = NULL;
	if (win->img)
		mlx_destroy_image(win->img);
	win->img = NULL;
	ft_free_t_window(win);
	win = NULL;
	ft_printf("total free");
}
