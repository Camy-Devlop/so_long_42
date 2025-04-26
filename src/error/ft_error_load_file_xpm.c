/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_load_file_xpm.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:53:17 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/26 20:53:22 by isadbaib         ###   ########.fr       */
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
