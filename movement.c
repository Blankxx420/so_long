/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:24:48 by blankx            #+#    #+#             */
/*   Updated: 2024/01/18 12:55:56 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_movement(int keycode, t_game **game)
{
	if (keycode == XK_w)
	{
		move_up(game);
	}
	if (keycode == XK_s)
	{
		move_down(game);
	}
	if (keycode == XK_d)
	{
		move_right(game);
	}
	if (keycode == XK_a)
	{
		move_left(game);
	}
	return (0);
}

void move_up(t_game **game)
{	
	int x;
	int y;
	
	x = (*game)->x_player;
	y = (*game)->y_player;
	update_player_img('w', game);
	if ((*game)->finalmap[y - 1][x] == 'C')
	{
		(*game)->finalmap[y - 1][x] = '0';
		(*game)->inventory++;
	}
	if ((*game)->finalmap[y - 1][x] == '0')
		player_draw(game, x , y - 1);
}

void move_down(t_game **game)
{	
	int x;
	int y;
	
	x = (*game)->x_player;
	y = (*game)->y_player;
	update_player_img('s', game);
	if ((*game)->finalmap[y + 1][x] == 'C')
	{
		(*game)->finalmap[y + 1][x] = '0';
		(*game)->inventory++;
	}
	if ((*game)->finalmap[y + 1][x] == '0')
		player_draw(game, x, y + 1);
}

void move_right(t_game **game)
{	
	int x;
	int y;
	
	x = (*game)->x_player;
	y = (*game)->y_player;
	update_player_img('d', game);
	if ((*game)->finalmap[y][x + 1] == 'C')
	{
		(*game)->finalmap[y ][x + 1] = '0';
		(*game)->inventory++;
	}
	if ((*game)->finalmap[y][x + 1] == '0')
		player_draw(game, x + 1, y);
}

void move_left(t_game **game)
{	
	int x;
	int y;
	
	x = (*game)->x_player;
	y = (*game)->y_player;
	update_player_img('a', game);
	if ((*game)->finalmap[y][x - 1] == 'C')
	{
		(*game)->finalmap[y ][x - 1] = '0';
		(*game)->inventory++;
	}
	if ((*game)->finalmap[y][x - 1] == '0')
		player_draw(game, x - 1, y);
}