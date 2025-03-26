/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:02:29 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/26 15:38:42 by isadbaib         ###   ########.fr       */
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
	while (i < NB_ASSET)
	{
		win->room->asset[i] = (t_img*) mlx_xpm_file_to_image(win->mlx, (char *)NOM[i] , &height, &width);
		i++;
	}
}

//void	ft_draw_map()
