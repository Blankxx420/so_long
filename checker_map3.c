/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:17:38 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/22 12:02:33 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_spread2(char **final_map, int x, int y, int nbr_line)
{
	int	nbr_char;

	nbr_char = ft_strlen(final_map[0]) - 1;
	final_map[y][x] = 'P';
	if (final_map[y + 1][x] != '1'
		&& final_map[y + 1][x] != 'P'
		&& y + 1 < nbr_line)
		ft_spread2(final_map, x, y + 1, nbr_line);
	if (final_map[y - 1][x] != '1'
		&& final_map[y - 1][x] != 'P'
		&& y - 1 > 0)
		ft_spread2(final_map, x, y - 1, nbr_line);
	if (final_map[y][x + 1] != '1'
		&& x + 1 < nbr_char && final_map[y][x + 1] != 'P')
		ft_spread2(final_map, x + 1, y, nbr_line);
	if (final_map[y][x - 1] != '1'
		&& x - 1 > 0 && final_map[y][x - 1] != 'P')
		ft_spread2(final_map, x - 1, y, nbr_line);
	return (final_map);
}

int	is_end2(char **final_map)
{
	int	i;
	int	j;

	i = 0;
	while (final_map[i])
	{
		j = 0;
		while (final_map[i][j])
		{
			if (final_map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}