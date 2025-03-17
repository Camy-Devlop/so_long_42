/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isadbaib <isadbaib@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:44:34 by isadbaib          #+#    #+#             */
/*   Updated: 2025/03/17 16:39:14 by isadbaib         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static bool ft_filt(int key)
{
    if (key == 122)
        return (true);
    else if (key == 113)
        return (true);
    else if (key == 100)
        return (true);
    else if (key == 115)
        return (true);
    else if (65361 <= key && key <= 65364)
        return (true);
    else
        return (false);
}

int ft_key_move(int keycode, t_window data)
{   
    if (keycode == 122)
        ft_printf("valeur haut %d\n",keycode);
    else if (keycode == 113)
        ft_printf("valeur gauche %d\n",keycode);
    else if (keycode == 100)
        ft_printf("valeur droit %d\n",keycode);
    else if (keycode == 115)
        ft_printf("valeur bas %d\n",keycode);
    else if (keycode == 65361)
        ft_printf("valeur gauche %d\n",keycode);
    else if (keycode == 65362)
        ft_printf("valeur haut %d\n",keycode);
    else if (keycode == 65363)
        ft_printf("valeur droit %d\n",keycode);
    else if (keycode == 65364)
        ft_printf("valeur bas %d\n",keycode);    
    if (ft_filt(keycode))
        ft_printf("number of move %d\n",(data->cpt++));
    return (0);
}

