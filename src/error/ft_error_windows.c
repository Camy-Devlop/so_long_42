/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:43:54 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/14 10:21:26 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_err_win(size_t err)
{
	if (err == 0)
		ft_printf("Error in window size\n");
	if (err == 1)
		ft_printf("Error  you don't give title \n");
	if (err == 2)
		ft_printf("Error in title not creation \n");
	if (err == 3)
		ft_printf("Error in init window\n");
	if (err == 4)
		ft_printf("Error in init mlx\n");
	if (err == 5)
		ft_printf("Error in init t_win_list of mlx\n");
}
