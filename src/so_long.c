/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:23:51 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/28 01:02:40 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_print_map1(t_card m)
{
	size_t i = 0;
	ft_printf("hauteur test %d\n",m->size.height);
	while (i < m->size.height)
		ft_printf("%s",m->map[i++]);
	printf("-------F-------\n");
}

static t_game_room	ft_preparing_game(char **tab)
{
	t_game_room	room;
	t_map		m;
	t_card		tmp;

	if(!ft_file_check(tab[1]))
		return (NULL);
	room = ft_calloc(1,sizeof(struct s_game_room));
	if (!room)
		return (ft_printf("Error not create room"), NULL);
	m = ft_recover_card(tab[1]);
	room->card = ft_create_card(m);
	m = NULL;
	if (!room->card)
		return (ft_free_t_card(room->card,
			room->card->size.height - 1), free(room), NULL);
	room->p = create_t_player(ft_cp_t_card(room->card));
	if (!room->p)
		return (NULL);
	tmp = ft_cp_t_card(room->card);
	if (!tmp)
		return (ft_free_t_card(room->card, room->card->size.height - 1),
			free(room), NULL);
	if (!back_traking(tmp, *room->p->coord, false))
		return (ft_printf("Error E not find\n"),
			ft_free_t_card(tmp, tmp->size.height - 1),
			ft_free_t_card(room->card,room->card->size.height - 1), NULL);
	return (ft_free_t_card(tmp, tmp->size.height - 1), room);
}

/*
void ft_run()
*/

int main(int n, char **tab)
{
	t_window win;

	(void)tab;
	(void)n;
	if (n != 2)
		return (-1);
	win = ft_create_window(600, 800, "so long !!!!!");
	if (!win)
		return (ft_err_win(3), -1);
	win->room = ft_preparing_game(tab);
	if (!win->room)
		return (ft_free_t_window(win), -1);
	
	ft_load_images(win);

	if (win->room->asset)
	{
		mlx_put_image_to_window(win->mlx, win->win, win->room->asset[0], 0, 0);
	mlx_put_image_to_window(win->mlx, win->win, win->room->asset[1], 51, 0);
	mlx_put_image_to_window(win->mlx, win->win, win->room->asset[2],2*51, 0);
	mlx_put_image_to_window(win->mlx, win->win, win->room->asset[3],3*51, 0);
	}
	mlx_hook(win->win, 33, 1L<<17, ft_close, win);	
	mlx_hook(win->win, 2, 1L<<0, ft_key_move, win);	
	mlx_loop(win->mlx);	
	//free(win);
//	mlx_clear_window(win->mlx, win->win);
	//ft_free_win(vars);
	//ft_close(1,win);
	//free(win->title);
	//free(win->win);
//	if (!room)
//		return (-1);
//	ft_print_map1(room->card);
//	ft_free_all(room->card);
//	ft_free_player(room->p);
//	room = NULL;
//	ft_printf("fini\n");
	return (0);
}
