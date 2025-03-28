/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_allowance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:47:28 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/28 01:06:09 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_err_allowance(size_t err)
{
	if (err == 0)
		ft_printf("Error of allowance\n");
	if (err == 1)
		ft_printf("Error of allowance t_card\n");
	if (err == 2)
		ft_printf("Error of allowance t_card for map\n");
	if (err == 3)
		ft_printf("Error of allowance t_card for copy of the map\n");
	if (err == 4)
		ft_printf("Error of allowance for image asset\n");
}
