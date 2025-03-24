/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:54:46 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/24 13:02:12 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_img *ft_create_new_image(t_window w)
{
	t_img *img;
	if (!w)
		return (NULL);
	img =  mlx_new_image(w->mlx, w->width, w->height);
    if (!img)
		return (ft_err_image(0), NULL);
	return (img);
}

t_img *ft_load_image(char *address, t_window win)
{
	int	height;
	int	width;
	t_img	m;

	m = mlx_xpm_file_to_image(win->mlx,address, &height, width);
	if (!m)
		return (NULL);
	return (m);
}


