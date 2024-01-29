/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:21:30 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/29 07:16:07 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int char_is_valid(char c)
{
	if (c != 'P' && c != '1' && c != '0' && c != 'E' && c != 'C')
		return (1);
	return (0);
}
int	is_rectangle(char **final_map, char *map)
{
	int	nbr_line;
	int	nbr_char;
	int	i;

	nbr_line = count_line(map);
	nbr_char = ft_strlen(final_map[0]);
	i = 1;
	while (ft_strlen(final_map[i]) == nbr_char)
	{
		if (ft_strlen(final_map[i]) != nbr_char)
			return (1);
		i++;
	}
	if (nbr_line < nbr_char || nbr_line > nbr_char)
		return (0);
	return (1);
}

int	check_map_char(char **final_map, int nbr_item)
{
	int	i;
	int	j;
	int	p_count;
	int	e_count;

	i = 0;
	p_count = 0;
	e_count = 0;
	if (nbr_item == 0)
		return (1);
	while (final_map[i])
	{
		j = 0;
		while (final_map[i][j])
		{
			if (char_is_valid(final_map[i][j]))
				return (1);
			if (final_map[i][j] == 'P')
				p_count++;
			if (final_map[i][j] == 'E')
				e_count++;
			j++;
		}
		i++;
	}
	if (p_count != 1 && e_count != 1)
		return (1);
	return (0);
}

int	map_is_close(char **final_map, int nbrline)
{
	int	i;
	int	j;
	i = 0;
	while (final_map[i])
	{
		j = 0;
		while (final_map[i][j])
		{
			if (final_map[0][j] != '1'
				|| final_map[nbrline - 1][j] != '1'
				|| final_map[i][0] != 1
				|| final_map[i][ft_strlen(final_map[j] - 1)] != 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_spread(char **final_map, int x, int y)
{
	final_map[x][y] = 'P';
	if (final_map[x + 1][y] != '1' && final_map[x + 1][y] != 'E')
		ft_spread(final_map, x + 1, y);
	if (final_map[x - 1][y] != '1' && final_map[x + 1][y] != 'E')
		ft_spread(final_map, x - 1, y);
	if (final_map[x][y + 1] != '1' && final_map[x + 1][y] != 'E')
		ft_spread(final_map, x, y + 1);
	if (final_map[x][y - 1] != '1' && final_map[x + 1][y] != 'E')
		ft_spread(final_map, x, y - 1);
	return (final_map);
}


