/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:23:51 by isadbaib          #+#    #+#             */
/*   Updated: 2025/05/03 19:19:28 by isadbaib         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static bool	ft_init1(char **tab, t_game_room *room, t_map *m, t_card *tmp)
{
	*room = NULL;
	*m = NULL;
	*tmp = NULL;
	(void)tmp;
	if (!ft_file_check(tab[1]))
		return (false);
	*room = ft_calloc(1, sizeof(struct s_game_room));
	if (!*room)
		return (ft_printf("Error not create room"), false);
	*m = ft_recover_card(tab[1]);
	(*room)->card = ft_create_card(*m);
	*m = NULL;
	if (!(*room)->card)
		return (free(*room), false);
	(*room)->p = create_t_player(ft_cp_t_card((*room)->card));
	if (!(*room)->p)
		return (false);
	*tmp = ft_cp_t_card((*room)->card);
	if (ft_check_card_map((*tmp)->map, &(*room)->card->size) == false)
	{
		ft_free_t_card(*tmp, (*room)->card->size.height - 1);
		*tmp = NULL;
	}
	return (true);
}



static t_game_room	ft_preparing_game(char **tab)
{
  t_game_room	room;
	t_map		m;
	t_card		tmp;

	if (!ft_init1(tab, &room, &m, &tmp))
		return (NULL);
	if (!tmp)
		return (ft_free_room(room), NULL);
	if (!back_traking(tmp, *room->p->coord, false))
		return (ft_printf("Error E not find\n"), ft_free_t_card(tmp,
				tmp->size.height - 1), ft_free_room(room), NULL);
	ft_free_t_card(tmp, tmp->size.height - 1);
	tmp = ft_cp_t_card(room->card);
	if (!tmp)
		return (ft_free_t_card(room->card, room->card->size.height - 1),
			free(room), NULL);
	room->p->bag.nb = nb_collector(tmp);
	if (!back_traking_c(tmp, &room->p->bag, *room->p->coord, false))
		return (ft_printf("Error collecter not find\n"), ft_free_t_card(tmp,
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
	if (!win->room->asset)
		return (ft_free_all(win), ft_err_load_file_xpm(1), -1);
	ft_draw_map(win);
	win->room->card->map[win->room->p->coord->y][win->room->p->coord->x] = '0';
	mlx_hook(win->win, 33, 1L << 17, ft_close, win);
	mlx_hook(win->win, 2, 1L << 0, ft_key_move, win);
	mlx_loop(win->mlx);
	return (0);
}
