/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_read_end_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:11:27 by isadbaib          #+#    #+#             */
/*   Updated: 2025/02/25 11:56:12 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int ft_goto_end_file(int fd)
{
	char	*tmp;
	size_t	cpt;

	cpt = 0;
	while (1)
	{	
		tmp = get_next_line(fd);	
		if (!tmp && cpt == 0)
			break;
		else if (!tmp)
			break;
		free(tmp);
		tmp = NULL;
		cpt++;
	}
	if (cpt == 0)
		return (-1);
	return (fd);
}
