/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_card.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:30:28 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/12 05:36:05 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_print_map2(t_card m)
{
	if (!m)
		return ;
	size_t i = 0;
	ft_printf("hauteur test %d\n",m->size.height);
	while (i < m->size.height)
		ft_printf("%s",m->map[i++]);
	printf("-------CP-------\n");
}


t_card ft_cp_t_card(t_card c)
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
			return (ft_err_allowance(3), ft_free_t_card(new,i), NULL);
		i++;
	}
	return (new);
}

