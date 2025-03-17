/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_gamer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:47:30 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/11 10:26:55 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_free_player(t_player p)
{
	if (!p)
		return ;
	ft_free_coord(p->coord);
	p->coord = NULL;
	free(p);
	p = NULL;	
}
