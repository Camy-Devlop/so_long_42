/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_card.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:42:04 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/04 23:33:29 by isadbaib         ###   ########.fr       */
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
