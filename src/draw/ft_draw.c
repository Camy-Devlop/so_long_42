/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:06:23 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/16 16:01:37 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void ft_draw(t_img *data, t_pixel pix, int color)
{
	char	*dst;
	dst = data->data + (pix.y * data->size_line + pix.x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
