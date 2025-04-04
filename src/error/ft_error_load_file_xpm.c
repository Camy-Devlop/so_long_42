/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_load_file_xpm.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 00:44:18 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/04 23:39:34 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_err_load_file_xpm(size_t err)
{
	if (err == 0)
		ft_printf("Error leading a file not find\n");
}
