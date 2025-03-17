/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_t_card.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:32:53 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/07 15:35:38 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_err_t_card(size_t err)
{
	if (err == 1)
		ft_printf("Error this map imposible to find the exit\n");
	if (err == 2)
		ft_printf("Error impossible to collect every collector\n");
}
