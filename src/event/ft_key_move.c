/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:44:34 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/10 23:20:09 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static bool	ft_filt(int key, t_window data)
{
	if (key == 119 || key == 65362)
		return (ft_move_up(data));
	else if (key == 97 || key == 65361)
		return (ft_move_left(data));
	else if (key == 100 || key == 65363)
		return (ft_move_right(data));
	else if (key == 115 || key == 65364)
		return (ft_move_down(data));
	else
		return (false);
}

int	ft_key_move(int keycode, t_window data)
{
	else if (keycode == 65307)
		ft_close(data);
	if (ft_filt(keycode, data))
		ft_printf("number of move %d\n", (data->cpt++));
	return (0);
}
