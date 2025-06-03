/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:44:34 by isadbaib          #+#    #+#             */
/*   Updated: 2025/06/03 11:16:15 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static bool	ft_filt(int key, t_window data)
{
	if (key == 119 || key == 65362)
		data->up = true;
	else if (key == 115 || key == 65364)
		data->down = true;
	if (key == 97 || key == 65361)
		data->left = true;
	else if (key == 100 || key == 65363)
		data->right = true;
	return (false);
}

int	ft_move(t_window data)
{
	ft_wait(27000000);
	if (data->up)
		ft_move_up(data);
	else if (data->down)
		ft_move_down(data);
	if (data->left)
		ft_move_left(data);
	else if (data->right)
		ft_move_right(data);
	return (0);
}

static void	ft_filt2(int key, t_window data)
{
	if (key == 119 || key == 65362)
		data->up = false;
	if (key == 97 || key == 65361)
		data->left = false;
	if (key == 100 || key == 65363)
		data->right = false;
	if (key == 115 || key == 65364)
		data->down = false;
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
	ft_filt2(keycode, data);
	return (0);
}
