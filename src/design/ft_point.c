/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:54:27 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/16 14:25:51 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_point	ft_point(int x, int y, int color)
{
	t_point p;

	if (x < 0 || y < 0)
		return (NULL);
	p = ft_calloc(1,sizeof(struct s_point));
	if (!p)
		return (NULL);
	p->pixel.x = x;
	p->pixel.y = y;
	p->color = color;
	return (p);
}


