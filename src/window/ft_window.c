/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:53:22 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/14 22:20:32 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_window	ft_create_window(int x, int y, char *title)
{
	t_window w;

	if (x <= 0 || y <= 0)
		return (ft_err_win(0), NULL);
	w = ft_calloc(1, sizeof(struct s_window));
	if (!w)
		return (ft_err_win(3),NULL);
	if (!title)
		return (ft_err_win(1), ft_free_t_window(w), NULL);
	w->title = ft_strdup(title);
	if (!w->title)
		return (ft_err_win(2),ft_free_t_window(w), NULL);
	w->mlx = mlx_init();
	if (!w->mlx)
		return (ft_err_win(4), ft_free_t_window(w), NULL);
	w->win = mlx_new_window(w->mlx, x, y, w->title);
	if (!w->win)
		return (ft_err_win(5), ft_free_t_window(w), NULL);
	w->height = y;
	w->width = x;
	w->img = ft_create_new_image(w);
	if(!w->img)
		return (ft_err_win(6), ft_free_t_window(w), NULL);
	return (w);
}
