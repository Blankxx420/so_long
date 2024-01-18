/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:10:35 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/18 12:11:39 by brguicho         ###   ########.fr       */
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

void display_map(t_game **game)
{
	int x;
	int y;
	
	y = 0;
	while ((*game)->finalmap[y])
	{	x = 0;
		while ((*game)->finalmap[y][x])
		{
			if ((*game)->finalmap[y][x] == '1')
				mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img_wall, x * 48, y * 48);
			if ((*game)->finalmap[y][x] == '0')
				mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img_ground, x * 48, y * 48);
			if ((*game)->finalmap[y][x] == 'P')
				player_draw(game, x, y);
			if ((*game)->finalmap[y][x] == 'C')
				mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img_item, x * 48, y * 48);
			if ((*game)->finalmap[y][x] == 'E')
				mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img_exit, x * 48, y *48);
			x++;
		}
		y++;
	}
}