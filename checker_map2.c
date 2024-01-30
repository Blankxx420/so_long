/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:04:55 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/30 15:31:21 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_end(char **final_map)
{
	int	i;
	int j;

	i = 0;
	while (final_map[i])
	{
		j = 0;
		printf("%s", final_map[i]);
		while (final_map[i][j])
		{
			if (final_map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


int	check_map(t_game **game, char *argv)
{
	(void) argv;
	(void) game;
	// // if (map_is_close((*game)->copy_map, count_line(argv))
	// // 	&& is_rectangle((*game)->copy_map, argv)
	// // 	&& check_map_char((*game)->copy_map, (*game)->nbr_item))
	// // {
	// 	ft_spread((*game)->copy_map,(*game)->x_player, (*game)->y_player);
	// 	if (is_end((*game)->copy_map))
	// 		return (1);
	// 	else
	// 	{
	// 		ft_printf("%s\n", "map error");
	// 		return (0);
	// 	}
	// //}
	return (1);
}