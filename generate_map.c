/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:54:26 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/16 14:57:21 by blankx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	count_line(char *str)
{
	int count;
	int	fd;
	char *line;
	
	count = 0;
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char **generate_map(char *str)
{
	int nbr_line;
	int	fd;
	char **final_map;
	char *line;
	int	i;
	
	nbr_line = count_line(str);
	fd = open(str, O_RDONLY);
	final_map = ft_calloc(nbr_line + 1, sizeof(char *));
	if (!final_map)
		return (NULL);
	i = 0;
	while (i <= nbr_line + 1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		final_map[i] = ft_strdup(line);
		if (!final_map[i])
			return (NULL);
		free(line);
		i++;
	}
	close(fd);
	return (final_map);
}

void display_map(t_vars **vars)
{
	int x;
	int y;
	t_vars *tmp;
	
	y = 0;
	tmp = (*vars);
	while (tmp->finalmap[y])
	{	x = 0;
		while (tmp->finalmap[y][x])
		{
			if (tmp->finalmap[y][x] == '1')
				render_wall(vars, x * 48, y * 48);
			if (tmp->finalmap[y][x] == '0')
				render_ground(vars, x * 48, y * 48);
			if (tmp->finalmap[y][x] == 'P')
				render_player_down(vars, x * 48, y * 48);
			if (tmp->finalmap[y][x] == 'C')
				render_item(vars, x * 48, y * 48);
			if (tmp->finalmap[y][x] == 'E')
				render_wall(vars, x * 48, y * 48);
			x++;
		}
		y++;
	}
}