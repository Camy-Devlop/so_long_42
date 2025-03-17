/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_t_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:53:02 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/07 15:35:08 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_err_t_map(size_t err)
{
	if (err == 0)
		ft_printf("Error heigth ou width not correct \n");
	if (err == 1)
		ft_printf("Error the map must not be a square\n");
	if (err == 2)
		ft_printf("Error not-regular rectangle\n");
}
