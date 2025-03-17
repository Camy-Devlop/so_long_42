/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_traking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 02:32:49 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/08 22:03:54 by isadbaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	back_traking(t_card c, t_coord now, bool t);

static bool	ft_search(t_card c, t_coord now, bool t)
{
	if (c->map[now.y - 1][now.x] != '1' && c->map[now.y - 1][now.x] != 'D')
	{
		return (t = back_traking(c, (t_coord){now.x, now.y - 1}, false), t);
	}
	else if (c->map[now.y][now.x + 1] != '1'
			&& c->map[now.y][now.x + 1] != 'D')
	{
		return (t = back_traking(c, (t_coord){now.x + 1, now.y}, false), t);
	}
	else if (c->map[now.y][now.x - 1] != '1'
			&& c->map[now.y][now.x - 1] != 'D')
	{
		return (t = back_traking(c, (t_coord){now.x - 1, now.y}, false), t);
	}
	else if (c->map[now.y + 1][now.x] != '1'
			&& c->map[now.y + 1][now.x] != 'D')
	{
		return (t = back_traking(c, (t_coord){now.x, now.y + 1}, false), t);
	}
	else
		return (false);
}

bool	back_traking(t_card c, t_coord now, bool t)
{
	int	i;

	if (1 > now.y || now.y > c->size.height - 1
		|| 1 > now.x || now.x > c->size.width - 1)
		return (false);
	if (c->map[now.y][now.x] == 'E')
		return (true);
	c->map[now.y][now.x] = 'D';
	i = 0;
	while (i < 4)
	{
		if (ft_search(c, now, t))
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
