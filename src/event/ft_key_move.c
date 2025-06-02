/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:44:34 by isadbaib          #+#    #+#             */
/*   Updated: 2025/06/02 11:56:22 by isadbaib         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static bool	ft_filt(int key, t_window data)
{
	if ((key == 119 || key == 65362) && data->up)
		return (ft_move_up(data));
	else if ((key == 97 || key == 65361) && data->left)
		return (ft_move_left(data));
	else if ((key == 100 || key == 65363) && data->right)
		return (ft_move_right(data));
	else if ((key == 115 || key == 65364) && data->down)
		return (ft_move_down(data));
	else
		return (false);
}
static bool	ft_filt2(int key, t_window data)
{
	if (key == 119 || key == 65362)
		return (data->up = true);
	else if (key == 97 || key == 65361)
		return (data->left = true);
	else if (key == 100 || key == 65363)
		return (data->right = true);
	else if (key == 115 || key == 65364)
		return (data->down = true);
	else
		return (false);
}


int	ft_key_move(int keycode, t_window data)
{
	if (keycode == 65307)
		ft_close(data);
	if (ft_filt(keycode, data))
		ft_printf("number of move %d\n", (data->cpt++));
	return (0);
}

int	ft_key_move2(int keycode, t_window data)
{
	if (keycode == 65307)
		ft_close(data);
	if (ft_filt2(keycode, data))
	{
		ft_printf("number of move %d\n", (data->cpt++));
	}
	return (1);
}
