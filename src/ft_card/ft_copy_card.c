/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_card.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:30:28 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/04 23:31:56 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_card	ft_cp_t_card(t_card c)
{
	t_card	new;
	size_t	i;

	if (!c)
		return (NULL);
	new = ft_calloc(1, sizeof(struct s_card));
	if (!new)
		return (ft_err_allowance(1), NULL);
	new->map = ft_calloc(c->size.height, sizeof(char *));
	if (!new->map)
		return (ft_err_allowance(2), free(new), NULL);
	i = 0;
	new->size.height = c->size.height;
	new->size.width = c->size.width;
	while (i < c->size.height)
	{
		new->map[i] = ft_strdup(c->map[i]);
		if (!new->map[i])
			return (ft_err_allowance(3), ft_free_t_card(new, i), NULL);
		i++;
	}
	return (new);
}
