/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:54:06 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/17 01:18:11 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
/*
procédure tracerCercle (entier rayon, entier x_centre, entier y_centre)
	déclarer entier x, y, m ;
	x ← 0 ;
	y ← rayon ;             // on se place en haut du cercle 
	m ← 5 - 4*rayon ;       // initialisation
	Tant que x <= y         // tant qu'on est dans le second octant
		tracerPixel( x+x_centre, y+y_centre ) ;
		tracerPixel( y+x_centre, x+y_centre ) ;
		tracerPixel( -x+x_centre, y+y_centre ) ;
		tracerPixel( -y+x_centre, x+y_centre ) ;
		tracerPixel( x+x_centre, -y+y_centre ) ;
		tracerPixel( y+x_centre, -x+y_centre ) ;
		tracerPixel( -x+x_centre, -y+y_centre ) ;
		tracerPixel( -y+x_centre, -x+y_centre ) ;
		si m > 0 alors	//choix du point F
			y ← y - 1 ;
			m ← m - 8*y ;
		fin si ;
		x ← x + 1 ;
		m ← m + 8*x + 4 ;
	fin tant que ;
fin de procédure ;

*/

void	circle( (int ray, int x_center, int y_center)
{
	int  x, y, m;
	x = 0 ;
	y = ray ;             // on se place en haut du cercle 
	m = 5 - 4 * ray ;       // initialisation
	while (x <= y)         // tant qu'on est dans le second octant
	{
		tracerPixel( x+x_centre, y+y_centre ) ;
		tracerPixel( y+x_centre, x+y_centre ) ;
		tracerPixel( -x+x_centre, y+y_centre ) ;
		tracerPixel( -y+x_centre, x+y_centre ) ;
		tracerPixel( x+x_centre, -y+y_centre ) ;
		tracerPixel( y+x_centre, -x+y_centre ) ;
		tracerPixel( -x+x_centre, -y+y_centre ) ;
		tracerPixel( -y+x_centre, -x+y_centre ) ;
		if (m > 0) 
		{
			y = y - 1 ;
			m = m - 8 * y ;
		}
		x = x + 1 ;
		m = m + 8*x + 4 ;
	}
}

