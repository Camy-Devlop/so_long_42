/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 20:49:44 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/26 20:51:33 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_draw(t_img *data, t_pixel pix, int color)
{
	char	*dst;

	dst = data->data + (pix.y * data->size_line + pix.x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
