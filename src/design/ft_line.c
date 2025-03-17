/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:54:15 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/17 20:00:00 by isadbaib         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_draw_line(t_point p1, t_point p2, t_img *data)
{
    int dx = abs(p2->pixel.x - p1->pixel.x);
    int sx = p1->pixel.x < p2->pixel.x ? 1 : -1;
    int dy = -abs(p2->pixel.y - p1->pixel.y);
    int sy = p1->pixel.y < p2->pixel.y ? 1 : -1;
    int err = dx + dy;
    int e2;
	t_pixel pix;

	pix.x =  p1->pixel.x;
	pix.y =  p1->pixel.y;
    while (1) 
	{
        ft_draw(data, pix, p1->color);
        if (pix.x == p2->pixel.x && pix.y == p2->pixel.y) break;
        e2 = 2 * err;
        if (e2 >= dy) 
		{
            err += dy;
            pix.x += sx;
        }
        if (e2 <= dx) 
		{
            err += dx;
            pix.y += sy;
        }
    }
}