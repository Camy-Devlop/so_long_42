/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_allowance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:52:04 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/26 20:52:11 by isadbaib         ###   ########.fr       */
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
