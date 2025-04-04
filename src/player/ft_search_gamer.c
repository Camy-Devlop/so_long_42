/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_gamer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:30:09 by isadbaib          #+#    #+#             */
/*   Updated: 2025/04/04 23:17:25 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static size_t	nb_player(t_card c)
{
	size_t	i;
	size_t	j;
	size_t	player;

	if (!c)
		return (0);
	if (!c->map)
		return (0);
	if (c->size.height < 3 || c->size.width < 3)
		return (0);
	i = 0;
	player = 0;
	while (i < c->size.height)
	{
		j = 0;
		while (j < c->size.width)
		{
			if (c->map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	return (player);
}

static t_coord	*ft_player_coord(t_card c)
{
	t_coord	*p;
	size_t	i;
	size_t	j;

	if (!c || !c->map || 1 != nb_player(c))
		return (NULL);
	p = ft_calloc(1, sizeof(t_coord));
	if (!p)
		return (ft_err_coord(0), NULL);
	i = 0;
	while (i < c->size.height)
	{
		j = 0;
		while (j < c->size.width)
		{
			if (c->map[i][j] == 'P')
				return (p->x = j, p->y = i, p);
			j++;
		}
		i++;
	}
	c = NULL;
	return (ft_err_player(0), ft_free_coord(p), p = NULL, NULL);
}

t_player	create_t_player(t_card c)
{
	t_coord		*coord;
	t_player	p;

	coord = ft_player_coord(c);
	if (!coord)
		return (NULL);
	if (1 > coord->y || coord->y > c->size.height - 1 || 1 > coord->x
		|| coord->x > c->size.width - 1)
		return (ft_free_coord(coord), ft_free_t_card(c, c->size.height - 1),
			NULL);
	p = ft_calloc(1, sizeof(struct s_player));
	if (!p)
		return (ft_free_coord(coord), ft_free_t_card(c, c->size.height - 1),
			NULL);
	p->coord = coord;
	coord = NULL;
	ft_free_t_card(c, c->size.height - 1);
	return (p);
}
// ft_err_t_card(1)
/*
void	ft_print_map(t_card m)
{
	size_t	i;

	i = 0;
	while (i < m->size.height)
		printf("%s",m->map[i++]);
	printf("--------------\n");
}
int	main(void)
{
	char **m = calloc(20, sizeof(char *));
	int i= 0;
 m[0] =strdup("1111111111111");


 m[1] =strdup("10010000000C1");
 m[2] =strdup("1000011111001");
 m[3] =strdup("1P0011E000001");
 m[4] =strdup("1111111111111");
 m[5] =strdup("10010100011110110001");
 m[6] =strdup("10100001000000001001");
 m[7] =strdup("1P100110001101100101");
 m[8] =strdup("10001000110000010001");
 m[9] =strdup("10110001001011001101");
 m[10]=strdup("10000100100100000001");
 m[11]=strdup("11001000010001011101");
 m[12]=strdup("10100011100110000001");
 m[13]=strdup("10001000001000100101");
 m[14]=strdup("10110100110011010001");
 m[15]=strdup("10000001000100001001");
 m[16]=strdup("10001100011001100101");
 m[17]=strdup("1E100010100010000001");
 m[18]=strdup("10110001001100011101");
 m[19]=strdup("11111111111111111111");

	t_card c = calloc(1, sizeof(struct s_card));
	c->map = m;
	c->size.height = strlen(c->map[0]);
	c->size.width = 5;
	t_coord coord = {11, 3};
	bool t = back_traking(c, coord, false);
	if (t)
	{
		printf("trouver\n");
	}
	else
	{
		printf("non trouver\n");
	}
	while(i < 5)
		free(c->map[i++]);
	free(c);
	free(m);
	return (0);
}*/
