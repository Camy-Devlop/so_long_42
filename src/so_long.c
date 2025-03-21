/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:23:51 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/21 13:57:01 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
/*
void ft_free_all(t_card card)
{
	return (ft_free_t_card(card, card->size.height - 1));
}
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
		return (free(room), NULL);
	room->p = create_t_player(ft_cp_t_card(room->card));
	if (!room->p)
		return (NULL);
	tmp = ft_cp_t_card(room->card);
	if (!tmp)
		return (ft_free_all(room->card), ft_free_t_card(room->card,
				room->card->size.height - 1), free(room), NULL);
	if (!back_traking(tmp, *room->p->coord, false))
				return (ft_printf("Error E not find\n"), ft_free_all(tmp),
						ft_free_all(room->card), NULL);
	return (ft_free_all(tmp), room);
}*/

/*
void ft_run()
*/

int main(int n, char **tab)
{
(void)tab;
(void)n;
//	t_game_room room;
	t_window win;
//	(void)win;
//	(void)win->mlx;
//	(void)win->win;
	ft_printf("tesst \n");
	if (n != 2)
		return (-1);
	ft_printf("tesst2 \n");
//	room = ft_preparing_game(tab);
	win = ft_create_window(600, 800, "so long !!!!!");
	
//	char *asset = WALL;
	int	height;
	int	width;
	
	t_img *image = mlx_xpm_file_to_image(win->mlx,WALL, &height,&width);
	void *image2 = mlx_xpm_file_to_image(win->mlx,STAR, &height,&width);
	
	
	
	//t_point pix;
	//t_point pix2;

//pix  = ft_point(10, 10, (int)0x00FF0000);
//	pix2 = ft_point(30, 142,(int)0x00FF0000);
	//ft_draw(win->img, pix);
	//ft_draw_line( ft_point(50, 10,(int)0x00FF0000), ft_point(11, 300, (int)0x00FF0000), win->img);
	if (image != NULL)
	{
		mlx_put_image_to_window(win->mlx, win->win, image, 0, 0);
		mlx_put_image_to_window(win->mlx, win->win, image2, 51, 0);
	}
	sleep(5);
	mlx_clear_window(win->mlx, win->win);
	sleep(5);
	//mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
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
