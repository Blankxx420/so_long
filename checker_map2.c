/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:04:55 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/02 11:09:30 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	check_argv(char *str)
{
	int len;
	len = ft_strlen(str) - 1;
	if (str[len - 3] != '.' 
		&& str[len - 2] != 'b'
		&& str[len - 1] != 'e'
		&& str[len] != 'r')
		return (0);
	return (1);
	
}
int	is_end(char **final_map)
{
	int	i;
	int j;

	i = 0;
	while (final_map[i])
	{
		j = 0;
		while (final_map[i][j])
		{
			if (final_map[i][j] == 'C' || final_map[i][j] == '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


int	check_map(t_game **game, char *argv)
{
	int i = 0;
	char **mapfloded;
	if (map_is_close((*game)->copy_map, count_line(argv))
		&& is_rectangle((*game)->copy_map, argv)
		&& check_map_char((*game)->copy_map, (*game)->nbr_item))
	{
		mapfloded = ft_spread((*game)->copy_map,(*game)->x_player, (*game)->y_player, count_line(argv));
		while (mapfloded[i])
		{
			printf("%s\n", mapfloded[i]);
			i++;
		}
		if (is_end((*game)->copy_map))
			return (1);
		else
		{
			ft_printf("%s\n", "map error");
			return (0);
		}
	}
	return (0);
}