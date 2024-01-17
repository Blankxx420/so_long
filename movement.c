/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:24:48 by blankx            #+#    #+#             */
/*   Updated: 2024/01/15 23:09:08 by blankx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	move(int keycode, t_vars *vars)
{
    int         x;
    int         y;

    x = 3;
    y = 7;
    
    if (keycode == XK_d)
    {
        render_player_right(&vars, (x + 1) * 48, y * 48);
        render_ground(&vars, (x) * 48, y * 48);
        x = x + 1;
    } 
}