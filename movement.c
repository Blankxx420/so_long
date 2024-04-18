/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:24:48 by blankx            #+#    #+#             */
/*   Updated: 2024/04/18 22:25:33 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_movement(int keycode, t_game **game)
{
	if (keycode == XK_w)
		move_up(game);
	if (keycode == XK_s)
		move_down(game);
	if (keycode == XK_d)
		move_right(game);
	if (keycode == XK_a)
		move_left(game);
	return (0);
}

void	move_up(t_game **game)
{
	int	x;
	int	y;

	x = (*game)->x_player;
	y = (*game)->y_player;
	if ((*game)->finalmap[y - 1][x] == 'E'
		&& (*game)->inventory == (*game)->nbr_item)
	{
		player_draw(game, x, y - 1, (*game)->img_player_up);
		close_game(game);
	}
	if ((*game)->finalmap[y - 1][x] == 'P')
		(*game)->finalmap[y - 1][x] = '0';
	if ((*game)->finalmap[y - 1][x] == 'C')
	{
		(*game)->finalmap[y - 1][x] = '0';
		(*game)->inventory++;
	}
	if ((*game)->finalmap[y - 1][x] == '0')
	{
		player_draw(game, x, y - 1, (*game)->img_player_up);
		(*game)->nbr_move++;
		ft_printf("move :%i\n", (*game)->nbr_move);
	}
}

void	move_down(t_game **game)
{
	int	x;
	int	y;

	x = (*game)->x_player;
	y = (*game)->y_player;
	if ((*game)->finalmap[y + 1][x] == 'E'
		&& (*game)->inventory == (*game)->nbr_item)
	{
		player_draw(game, x, y + 1, (*game)->img_player_down);
		close_game(game);
	}
	if ((*game)->finalmap[y + 1][x] == 'P')
		(*game)->finalmap[y + 1][x] = '0';
	if ((*game)->finalmap[y + 1][x] == 'C')
	{
		(*game)->finalmap[y + 1][x] = '0';
		(*game)->inventory++;
	}
	if ((*game)->finalmap[y + 1][x] == '0')
	{
		player_draw(game, x, y + 1, (*game)->img_player_down);
		(*game)->nbr_move++;
		ft_printf("move :%i\n", (*game)->nbr_move);
	}
}

void	move_right(t_game **game)
{
	int	x;
	int	y;

	x = (*game)->x_player;
	y = (*game)->y_player;
	if ((*game)->finalmap[y][x + 1] == 'E'
		&& (*game)->inventory == (*game)->nbr_item)
	{
		player_draw(game, x + 1, y, (*game)->img_player_right);
		close_game(game);
	}
	if ((*game)->finalmap[y][x + 1] == 'P')
		(*game)->finalmap[y][x + 1] = '0';
	if ((*game)->finalmap[y][x + 1] == 'C')
	{
		(*game)->finalmap[y][x + 1] = '0';
		(*game)->inventory++;
	}
	if ((*game)->finalmap[y][x + 1] == '0')
	{
		player_draw(game, x + 1, y, (*game)->img_player_right);
		(*game)->nbr_move++;
		ft_printf("move :%i\n", (*game)->nbr_move);
	}
}

void	move_left(t_game **game)
{
	int	x;
	int	y;

	x = (*game)->x_player;
	y = (*game)->y_player;
	if ((*game)->finalmap[y][x - 1] == 'E'
		&& (*game)->inventory == (*game)->nbr_item)
	{
		player_draw(game, x - 1, y, (*game)->img_player_left);
		close_game(game);
	}
	if ((*game)->finalmap[y][x - 1] == 'P')
		(*game)->finalmap[y][x - 1] = '0';
	if ((*game)->finalmap[y][x - 1] == 'C')
	{
		(*game)->finalmap[y][x - 1] = '0';
		(*game)->inventory++;
	}
	if ((*game)->finalmap[y][x - 1] == '0')
	{
		player_draw(game, x - 1, y, (*game)->img_player_left);
		(*game)->nbr_move++;
		ft_printf("move :%i\n", (*game)->nbr_move);
	}
}
