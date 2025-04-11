/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:23:51 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/11 21:51:54 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_game_room	ft_preparing_game(char **tab)
{
	t_game_room	room;
	t_map		m;
	t_card		tmp;

	if (!ft_file_check(tab[1]))
		return (NULL);
	room = ft_calloc(1, sizeof(struct s_game_room));
	if (!room)
		return (ft_printf("Error not create room"), NULL);
	m = ft_recover_card(tab[1]);
	room->card = ft_create_card(m);
	m = NULL;
	if (!room->card)
		return (free(room), NULL);
	room->p = create_t_player(ft_cp_t_card(room->card));
	if (!room->p)
		return (NULL);
	tmp = ft_cp_t_card(room->card);
	if (!tmp)
		return (ft_free_t_card(room->card, room->card->size.height - 1),
			free(room), NULL);
	if (!back_traking(tmp, *room->p->coord, false))
		return (ft_printf("Error E not find\n"), ft_free_t_card(tmp,
				tmp->size.height - 1), ft_free_room(room), NULL);
	return (ft_free_t_card(tmp, tmp->size.height - 1), room);
}

int	main(int n, char **tab)
{
	t_window	win;

	(void)tab;
	(void)n;
	if (n != 2)
		return (-1);
	win = ft_create_window(3840, 2160, "so long !!!!!");
	if (!win)
		return (ft_err_win(3), -1);
	win->room = ft_preparing_game(tab);
	if (!win->room)
		return (ft_free_t_window(win), -1);
	ft_load_images(win);
	ft_draw_map(win);
	win->room->card->map[win->room->p->coord->y][win->room->p->coord->x] = '0';
	mlx_hook(win->win, 33, 1L << 17, ft_close, win);
	mlx_hook(win->win, 2, 1L << 0, ft_key_move, win);
	mlx_loop(win->mlx);
	return (0);
}
