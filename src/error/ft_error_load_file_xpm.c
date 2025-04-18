/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_load_file_xpm.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 00:44:18 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/18 21:21:50 by isadbaib         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_err_load_file_xpm(size_t err)
{
	if (err == 0)
		ft_printf("Error leading a file not find\n");
	if (err == 1)
			ft_printf("Error loading a file impossible\n");
}
