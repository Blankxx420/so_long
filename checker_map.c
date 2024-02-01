/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:21:30 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/31 15:48:48 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int char_is_valid(char c)
{
	if (c != 'P' && c != '1' && c != '0' && c != 'E' && c != 'C')
		return (0);
	return (1);
}
int	is_rectangle(char **final_map, char *map)
{
	int	nbr_line;
	int	nbr_char;
	int	i;

	nbr_line = count_line(map);
	nbr_char = ft_strlen(final_map[0]);
	i = 0;
	while (final_map[i])
	{
		if (ft_strlen(final_map[i]) != nbr_char)
			return (0);
		i++;
	}
	if (nbr_line < nbr_char || nbr_line > nbr_char)
		return (1);
	return (0);
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
		return (0);
	while (final_map[i])
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
		i++;
	}
	if (p_count != 1 && e_count != 1)
		return (0);
	return (1);
}

int	map_is_close(char **final_map, int nbrline)
{
	int	i;
	int	j;
	int len;
	
	i = 0;
	while (final_map[0][i] && final_map[nbrline - 1][i])
	{
		if (final_map[0][i] != '1' || final_map[nbrline - 1][i] != '1')
				return (0);
		i++;
	}
	j = 1;
	len = ft_strlen(final_map[j]) - 1;
	while (final_map[j])
	{
		if (final_map[j][0] != '1' || final_map[j][len] != '1')
				return (0);
		j++;
	}
	return (1);
}

char	**ft_spread(char **final_map, int x, int y, int nbr_line)
{
	int nbr_char;
	
	nbr_char = ft_strlen(final_map[0]) - 1;
    if (final_map[y + 1][x] != '1' 
		&& final_map[y + 1][x] != 'E'
		&& final_map[y + 1][x] != 'P'
		&& y + 1 < nbr_line)
    {
        final_map[y + 1][x] = 'P';
        ft_spread(final_map, x, y + 1, nbr_line);
    }
    if (final_map[y - 1][x] != '1' && final_map[y - 1][x] != 'E'
		&& final_map[y - 1][x] != 'P'
		&& y - 1 > 0)
    {
        final_map[y - 1][x] = 'P';
        ft_spread(final_map, x, y - 1, nbr_line);
    }
    if (final_map[y][x + 1] != '1' && final_map[y][x + 1] != 'E'
		&& x + 1 < nbr_char && final_map[y][x + 1] != 'P')
    {
        final_map[y][x + 1] = 'P';
        ft_spread(final_map, x + 1, y, nbr_line);
    }
    if (final_map[y][x - 1] != '1' && final_map[y][x - 1] != 'E'
		&& x - 1 > 0 && final_map[y][x - 1] != 'P')
    {
        final_map[y][x - 1] = 'P';
        ft_spread(final_map, x - 1,  y, nbr_line);
    }
    return (final_map);
}