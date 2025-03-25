/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:02:29 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/25 22:30:16 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_load_images(t_window win)
{
	int	i;
	int	height;
	int	width;

	i = 0;
	(void)i;
	win->room->asset = ft_calloc(NB_ASSET, sizeof(t_img *));
	if (!win->room->asset)
		return (ft_err_allowance(4), (void)0);
	win->room->asset[0] = (t_img*) mlx_xpm_file_to_image(win->mlx, WALL , &height, &width);
	win->room->asset[1] = (t_img*) mlx_xpm_file_to_image(win->mlx, STAR , &height, &width);
	win->room->asset[2] = (t_img*) mlx_xpm_file_to_image(win->mlx, DOOR , &height, &width);
	win->room->asset[3] = (t_img*) mlx_xpm_file_to_image(win->mlx, DOWN1 , &height, &width);
}

//void	ft_draw_map()
