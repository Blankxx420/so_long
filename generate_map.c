/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:10:35 by brguicho          #+#    #+#             */
/*   Updated: 2024/04/19 09:56:00 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	count_line(char *str)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		return (0);
	}
	line = get_next_line(fd);
	if (!line || line[0] == '\n')
	{
		free(line);
		return (0);
	}
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static char	**create_tab(int fd, int nbr_line)
{
	int		i;
	char	**final_map;
	char	*tmp;

	i = 0;
	tmp = ft_strdup("");
	while (i < nbr_line)
	{
		tmp = get_line_join(fd, tmp);
		if (!tmp)
		{
			free(tmp);
			return (NULL);
		}
		i++;
	}
	final_map = ft_split(tmp, '\n');
	if (!final_map)
	{
		free(final_map);
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (final_map);
}

char	**generate_map(char *str)
{
	int		nbr_line;
	int		fd;
	char	**final_map;

	nbr_line = count_line(str);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	final_map = create_tab(fd, nbr_line);
	close(fd);
	return (final_map);
}

static void	check_map_element(t_game **game, int y, int x)
{
	if ((*game)->finalmap[y][x] == '1')
	{
		mlx_put_image_to_window((*game)->mlx,
			(*game)->win, (*game)->img_wall, x * 48, y * 48);
	}
	else if ((*game)->finalmap[y][x] == '0')
	{
		mlx_put_image_to_window((*game)->mlx,
			(*game)->win, (*game)->img_ground, x * 48, y * 48);
	}
	else if ((*game)->finalmap[y][x] == 'P')
		player_draw(game, x, y, (*game)->img_player_down);
	else if ((*game)->finalmap[y][x] == 'C')
	{
		mlx_put_image_to_window((*game)->mlx,
			(*game)->win, (*game)->img_item, x * 48, y * 48);
	}
	else if ((*game)->finalmap[y][x] == 'E')
	{
		mlx_put_image_to_window((*game)->mlx,
			(*game)->win, (*game)->img_exit, x * 48, y * 48);
	}
}

void	display_map(t_game **game)
{
	int	x;
	int	y;

	y = 0;
	while ((*game)->finalmap[y])
	{
		x = 0;
		while ((*game)->finalmap[y][x])
		{
			check_map_element(game, y, x);
			x++;
		}
		y++;
	}
}
