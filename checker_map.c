/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:06:37 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/22 14:20:25 by brguicho         ###   ########.fr       */
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
	i = 1;
	while (ft_strlen(final_map[i]) == nbr_char)
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
		}
	}
	if (p_count == 1 && e_count == 1)
		return (1);
	return (0);
}

int	map_is_close(char **final_map, int nbrline)
{
	int	i;
	int	j;
	while (final_map[i])
	{
		j = 0;
		while (final_map[i][j])
		{
			if (final_map[0][j] != '1'
				|| final_map[nbrline - 1][j] != '1'
				|| final_map[i][0] != 1
				|| final_map[i][ft_strlen(final_map[j] - 1)] != 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	path_is_valid(char **final_map, int x, int y)
{
	
}