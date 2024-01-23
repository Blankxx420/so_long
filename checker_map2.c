/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:04:55 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/23 13:56:21 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_end(char **final_map)
{
	int	i;
	int j;
	while (final_map[i])
	{
		j = 0;
		while (final_map[i][j])
		{
			if (final_map[i][j] == 'C')
				return (0);
		}
	}
	return (1);
}


int	check_map(t_game **game, char *argv)
{
	if (map_is_close((*game)->copy_map, count_line(argv))
		&& is_rectangle((*game)->copy_map, argv)
		&& check_map_char((*game)->copy_map, (*game)->nbr_item))
	{
		
		ft_spread((*game)->copy_map,(*game)->x_player, (*game)->y_player);
		if (is_end((*game)->copy_map))
			return (0);
	}
	else
		ft_printf("%s\n", "map error");
}