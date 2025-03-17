/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:37:58 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/08 22:31:56 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_map	ft_create_element(int *nb)
{
	t_map	m;

	if (!nb)
		return (NULL);
	m = ft_calloc(1, sizeof(struct s_map));
	if (!m)
		return (NULL);
	m->nb = nb;
	return (m);
}

t_map	ft_add_element(char *s, int *nb)
{
	t_map	m;

	if (!s || !nb)
		return (NULL);
	m = ft_create_element(nb);
	if (!m)
		return (NULL);
	m->line = s;
	(*m->nb)++;
	return (m);
}

bool	ft_init(char *name_file, int *fd, int **i, t_map *v)
{
	if (!name_file)
		return (false);
	*fd = open(name_file, O_RDONLY);
	if (*fd < 0 || INT_MAX < *fd)
		return (false);
	*i = ft_calloc(1, sizeof(int));
	if (!*i)
		return (close(ft_goto_end_file(*fd)), false);
	*v = ft_add_element(get_next_line(*fd),*i);
	if (!(*v))
		return (close(ft_goto_end_file(*fd)), free(*i), false);
	return (true);
}

void	*ft_recover_card(char *name_file)
{
	t_map	v;
	t_map	res;
	char	*tmp;
	int		*i;
	int		fd;

	if (ft_init(name_file, &fd, &i, &v) == false)
		return (NULL);
	if (!v)
		return (free(i), i = NULL, NULL);
	res = v;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp && *i == 0)
			return (close(ft_goto_end_file(fd)),
				ft_free_t_map(res), free(i), NULL);
		if (!tmp)
			break ;
		v->next = ft_add_element(tmp, i);
		v = v->next;
	}
	close(fd);
	i = NULL;
	return (res);
}
