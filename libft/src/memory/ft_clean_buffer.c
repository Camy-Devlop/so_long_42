/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:41:58 by isadbaib          #+#    #+#             */
/*   Updated: 2024/12/02 11:34:46 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_clean_buff(char *s, ssize_t n)
{
	ssize_t	i;

	i = 0;
	if (!s || n == 0)
		return ;
	if (BUFFER_SIZE <= n)
		return (ft_bzero_gnl(s, BUFFER_SIZE * sizeof(char)), (void)0);
	while ((n + i) < BUFFER_SIZE)
	{
		s[i] = s[n + i];
		i++;
	}
	ft_bzero_gnl(s + BUFFER_SIZE - n, n * sizeof(char));
}
