/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:35:28 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/22 11:43:06 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_position(t_game **game, int x, int y)
{
	(*game)->x_player = x;
	(*game)->y_player = y;
}

void	count_item_get_player_pos(t_game **game, char **finalmap)
{
	int	i;
	int	j;

	i = 0;
	while (finalmap[i])
	{
		j = 0;
		while (finalmap[i][j])
		{
			if (finalmap[i][j] == 'C')
				(*game)->nbr_item++;
			if (finalmap[i][j] == 'P')
				set_player_position(game, i, j);
			j++;
		}
		i++;
	}
}