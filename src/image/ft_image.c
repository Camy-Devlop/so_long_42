/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:54:46 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/14 20:50:36 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_img *ft_create_new_image(t_window w)
{
	t_img *img;
	if (!w)
		return (NULL);
	img =  mlx_new_image(w->mlx, w->width, w->height);
    if (!img)
		return (ft_err_image(0), NULL);
	return (img);
}
