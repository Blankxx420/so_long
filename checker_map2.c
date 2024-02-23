/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:04:55 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/22 13:27:11 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	check_argv(char *str)
{
	int	len;

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
	int	j;

	i = 0;
	while (final_map[i])
	{
		j = 0;
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
	if (is_rectangle((*game)->copy_map, argv)
		&& map_is_close((*game)->copy_map, count_line(argv))
		&& check_map_char((*game)->copy_map, (*game)->nbr_item))
	{
		ft_spread((*game)->copy_map, (*game)->x_player,
			(*game)->y_player, count_line(argv));
		if (is_end((*game)->copy_map))
		{
			ft_spread2((*game)->copy_map2, (*game)->x_player,
				(*game)->y_player, count_line(argv));
			if (is_end2((*game)->copy_map2))
				return (1);
		}
		else
		{
			ft_printf("%s\n", "map error");
			return (0);
		}
	}
	return (0);
}

int	check_map_char2(char **final_map)
{
	int	i;
	int	j;
	int	p_count;
	int	e_count;

	i = -1;
	p_count = 0;
	e_count = 0;
	while (final_map[++i])
	{
		j = 0;
		while (final_map[i][j])
		{
			if (!char_is_valid(final_map[i][j]))
				return (0);
			if (final_map[i][j] == 'P')
				p_count++;
			if (final_map[i][j] == 'E')
				e_count++;
			j++;
		}
	}
	if (p_count != 1 || e_count != 1)
		return (0);
	return (1);
}
