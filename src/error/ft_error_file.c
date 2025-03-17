/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:45:41 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/07 15:29:47 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_err_file(size_t err)
{
	if (err == 0)
		ft_printf("Error extention not valable\n");
	if (err == 1)
		ft_printf("Error file not exist or not access\n");
	if (err == 2)
		ft_printf("Error file empty\n");
}
