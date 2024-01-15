/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:24:48 by blankx            #+#    #+#             */
/*   Updated: 2024/01/15 13:38:02 by blankx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int keycode, t_vars *vars)
{
    t_sprite    sprite;
    int         x;
    int         y;

    
    if (keycode == XK_d)
    {
        render_player(vars, x * 48 + 1, y * 48);
    }    
}