/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:09:11 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/04 23:33:11 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_free_t_map(t_map m)
{
	t_map	t;

	if (!m)
		return ;
	t = m->next;
	m->nb = NULL;
	if (m->line)
	{
		free(m->line);
		m->line = NULL;
	}
	free(m);
	ft_free_t_map(t);
	t = NULL;
}
