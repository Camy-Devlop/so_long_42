/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:02:29 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/28 01:54:43 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static bool	ft_check_file_xpm(char **asset)
{
	int	i;
	int	fd;

	i = 0;
	while (i < NB_ASSET)
	{
		fd = open(asset[i], O_RDONLY);
		if (fd == -1)
			return (false);
		close(fd);
		i++;
	}
	return (true);
}

char	**get_address_asset(void)
{
	char	**asset;

	asset = ft_calloc(NB_ASSET, sizeof(char *));
	if (!asset)
		return (NULL);
	asset[0] = "asset/wall.xpm";
	asset[1] = "asset/star.xpm";
	asset[2] = "asset/door.xpm";
	asset[3] = "asset/down-1.xpm";
	asset[4] = "asset/down-2.xpm";
	asset[5] = "asset/up-1.xpm";
	asset[6] = "asset/up-2.xpm";
	asset[7] = "asset/left-1.xpm";
	asset[8] = "asset/left-2.xpm";
	asset[9] = "asset/right-1.xpm";
	asset[10] ="asset/right-2.xpm";
	return (asset);
}

void	ft_load_images(t_window win)
{
	int	i;
	int	height;
	int	width;
	char	**asset;

	i = 0;
	asset = get_address_asset();
	printf("test ok %s\n", asset[0]);
	if (!asset)
		return (ft_err_allowance(4), (void)0);
	printf("test ok 2 \n");
	if (ft_check_file_xpm(asset) == false)
		return (free(asset), ft_err_load_file_xpm(0), (void)0);

	printf("test ok 3 \n");
	win->room->asset = ft_calloc(NB_ASSET, sizeof(t_img *));
	if (!win->room->asset)
	       return ;	
	while (i < NB_ASSET)	
	{
		win->room->asset[i] = (t_img *)mlx_xpm_file_to_image(win->mlx, asset[i],
				&height, &width);
		printf("%d\n",i);
		i++;
	}
	free(asset);
}

// void	ft_draw_map(void)
