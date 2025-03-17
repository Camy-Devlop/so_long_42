/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:26:38 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/14 18:20:42 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void ft_free_t_window(t_window w)
{
	if (w)
	{
		if (w->title)
			free(w->title);
		w->title = NULL;
		if (w->win)
			mlx_destroy_window(w->mlx, w->win);
		w->win = NULL;
		if (w->img)
			mlx_destroy_image(w->mlx, w->img);
		w->img = NULL;
		if (w->mlx)
			mlx_destroy_display(w->mlx);
		free(w->mlx);
		w->mlx = NULL;
		free(w);
	}
	w = NULL;
}
