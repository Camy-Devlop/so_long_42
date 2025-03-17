/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_card.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:49:03 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/08 21:48:03 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_card	ft_create_card(t_map m)
{
	t_card	c;
	t_map	t;
	int		i;

	if (!m)
		return (NULL);
	if (!ft_check_size_t_map(m))
		return (free(m->nb), ft_free_t_map(m), NULL);
	c = ft_calloc(1, sizeof(struct s_card));
	if (!c)
		return (free(m->nb), ft_free_t_map(m), NULL);
	c->size.height = *(m->nb);
	c->size.width = ft_strlen(m->line);
	c->map = ft_calloc(*(m->nb),sizeof(char *));
	if (!c->map)
		return (free(m->nb), ft_free_t_map(m),  ft_free_t_card(c, -1), NULL);
	i = 0;
	t = m;
	while (i < *(m->nb))
	{
		c->map[i] = ft_strdup(t->line);
		if (!c->map[i])
			return (t = NULL, ft_free_t_map(m), ft_free_t_card(c, i - 1), NULL);
		t = t->next;
		i++;
	}
	return (t = NULL, free(m->nb), ft_free_t_map(m), c);
}

