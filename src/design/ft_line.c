/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:54:15 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/17 00:35:45 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
 
/*
dx = x2 - x1
dy = y2 - y1
pour x de x1 à x2 faire
    y = y1 + dy * (x - x1) / dx
    plot(x, y)
fin pour	
*/
/*
static void ft_draw_line_h(t_pixel p1, int  y2, int color, t_img *data)
{
	int	i;
	int	dy;

	i = 0;
	dy = y2 - p1.y;	
	while (i < dy)
	{
		ft_draw(data, (t_pixel){p1.x, p1.y}, color);
		p1.y++;
		color += 256; 
		i++;
	}
}*/
void ft_draw_line(t_point p1, t_point p2, t_img *data)
{
	int		dx;
	int		dy;
	int 	pi;
	int		i;
	t_pixel pix;
	int		color;

	dx = p2->pixel.x - p1->pixel.x;
	dy = p2->pixel.y - p1->pixel.y;
	pi = 2 * (dy - dx);
	pix.x = p1->pixel.x;
	pix.y = p1->pixel.y;
	color = p1->color;
	i = p1->pixel.x;
	while (i < p2->pixel.x)
	{
		ft_draw(data, pix, color);
		pix.x++;
		if (pi >= 0)
			pix.y++;
		else if (pi < 0)
			pi = pi + 2 *dy;
		else
			pi = pi + 2 * (dy - dx);
			
	
		//pix.y = p1->pixel.y + dy * (pix.x - p1->pixel.x) / dx;
		//pix.x++;
		color += 256; 
		i++;
	}
}
/*
void ft_draw_line(t_point p1, t_point p2, t_img *data) {
	int		dx;
	int		dy;
	int 	e;
	int		i;
	t_pixel pix;
	int		color;

	pix.x = p1->pixel.x;
	pix.y = p1->pixel.y;
	color = p1->color;
	i = p1->pixel.x;
	e = p2->pixel.x - p1->pixel.x;
	dx = e * 2;
	dy = (p2->pixel.y - p1->pixel.y) * 2;
	while (i < p2->pixel.x)
	{
		ft_draw(data, pix, color);
		pix.x++;
		e -= dy;
		if (e <= 0)
		{
			pix.y++;
			e += dx;
		}
		//pix.y = p1->pixel.y + dy * (pix.x - p1->pixel.x) / dx;
		//pix.x++;
		color += 256; 
		i++;
	}
}*/
/*
void ft_draw_line(t_point p1, t_point p2, t_img *data)
{
	int		dx;
	int		dy;
	int		i;
	t_pixel pix;
	int		color;

	pix.x = p1->pixel.x;
	pix.y = p1->pixel.y;
	color = p1->color;
	i = 0;
	dx = p2->pixel.x - p1->pixel.x;
	dy = p2->pixel.y - p1->pixel.y;
	if (dx == 0)
		ft_draw_line_h(pix, p2->pixel.y, color, data);
	else if (dx == 0 && dy == 0)
		return ;
	else	
		while (i < dx)
		{
			pix.y = p1->pixel.y + dy * (pix.x - p1->pixel.x) / dx;
			ft_draw(data, pix, color);
			pix.x++;
			color += 256; 
			i++;
		}
}*/
