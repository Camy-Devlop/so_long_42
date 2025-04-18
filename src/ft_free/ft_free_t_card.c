/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_card.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:42:04 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/18 22:36:33 by isadbaib         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_free_t_card(t_card c, int i)
{
	if (!c)
		return ;
	if (c->map)
	{
		while (0 <= i)
			free(c->map[i--]);
		if (c->map)
			free(c->map);
	}
	free(c);
}
