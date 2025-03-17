/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_traking_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:30:48 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/10 13:30:54 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/so_long.h"

bool	back_traking_c(t_card c, t_bag *bag, t_coord now, bool t);

size_t	nb_collector(t_card c)
{
	size_t	i;
	size_t	j;
	size_t	collector;

	if (!c)
		return (0);
	if (!c->map)
		return (0);
	if (c->size.height < 3 || c->size.width < 3)
		return (0);
	i = 0;
	collector = 0;
	while (i < c->size.height)
	{
		j = 0;
		while (j < c->size.width)
		{
			if (c->map[i][j] == 'C')
				collector++;
			j++;
		}
		i++;
	}
	return (collector);
}

static bool	ft_search(t_card c, t_bag *bag, t_coord now, bool t)
{
	if (c->map[now.y - 1][now.x] != '1' && c->map[now.y - 1][now.x] != 'D')
	{
		return (t = back_traking_c(c, bag, (t_coord){now.x, now.y - 1},
			false), t);
	}
	else if (c->map[now.y][now.x + 1] != '1'
			&& c->map[now.y][now.x + 1] != 'D')
	{
		return (t = back_traking_c(c, bag, (t_coord){now.x + 1, now.y},
			false), t);
	}
	else if (c->map[now.y][now.x - 1] != '1'
			&& c->map[now.y][now.x - 1] != 'D')
	{
		return (t = back_traking_c(c, bag, (t_coord){now.x - 1, now.y},
			false), t);
	}
	else if (c->map[now.y + 1][now.x] != '1'
			&& c->map[now.y + 1][now.x] != 'D')
	{
		return (t = back_traking_c(c, bag, (t_coord){now.x, now.y + 1},
			false), t);
	}
	else
		return (false);
}

bool	back_traking_c(t_card c, t_bag *bag, t_coord now, bool t)
{
	int	i;

	if (bag->nb == 0)
		return (false);
	if (1 > now.y || now.y > c->size.height - 1
		|| 1 > now.x || now.x > c->size.width - 1)
		return (false);
	if (bag->nb == bag->nb_collected)
		return (true);
	if (c->map[now.y][now.x] == 'C')
		bag->nb_collected++;
	c->map[now.y][now.x] = 'D';
	i = 0;
	while (i < 4)
	{
		if (ft_search(c, bag, now, t))
		{
			t = true;
			break ;
		}
		i++;
	}
	if (t)
		return (t);
	return (false);
}
//ft_err_t_card(1)
/*
void	ft_print_map(t_card m)
{
	size_t i = 0;
	while (i < m->size.height)
		printf("%s",m->map[i++]);
	printf("--------------\n");
}
int	main(void)
{
	char **m = calloc(20, sizeof(char *));
	int i= 0;
 m[0] =strdup("11111111111111111111\n");
 m[1] =strdup("10010000001C11111111\n");
 m[2] =strdup("10000111110111111111\n");
 m[3] =strdup("1P001100000011111111\n");
 m[4] =strdup("10001100000011111111\n");
 m[5] =strdup("10010100011110110001\n");
 m[6] =strdup("101000010000C0001001\n");
 m[7] =strdup("10100110001101100101\n");
 m[8] =strdup("10001000110000010001\n");
 m[9] =strdup("10110001001011001101\n");
 m[10]=strdup("10000100100100000001\n");
 m[11]=strdup("11001C00010001011101\n");
 m[12]=strdup("10100011100110000001\n");
 m[13]=strdup("10001000001000100101\n");
 m[14]=strdup("10110100110011010001\n");
 m[15]=strdup("10000001000100001001\n");
 m[16]=strdup("100011C0011001100101\n");
 m[17]=strdup("1E100010100010000001\n");
 m[18]=strdup("1011C001001100011101\n");
 m[19]=strdup("11111111111111111111\n");

	t_card c = calloc(1, sizeof(struct s_card));
	c->map = m;
	c->size.height = 20;
	c->size.width = strlen(c->map[0]);
	t_coord coord = {3, 1};
	t_bag b;
	b.nb = nb_collector(c);
	b.nb_collected = 0;
	printf("nombre de C= %ld\n",b.nb);
	ft_print_map(c);
	bool t = back_traking_c(c,&b, coord, false);
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
