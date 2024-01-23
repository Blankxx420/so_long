/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:10:35 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/23 14:25:38 by brguicho         ###   ########.fr       */
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
		ft_printf("%s\n", "file error");
		return (0);
	}
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

static char	**create_tab(int fd, int nbr_line)
{
	int		i;
	char	*line;
	char	**final_map;

	i = 0;
	final_map = ft_calloc(nbr_line + 1, sizeof(char *));
	if (!final_map)
		return (NULL);
	while (i <= nbr_line + 1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		final_map[i] = ft_strdup(line);
		if (!final_map[i])
		{
			ft_free_tab(final_map);
			return (NULL);
		}
		free(line);
		i++;
	}
	return (final_map);
}

char	**generate_map(char *str)
{
	int		nbr_line;
	int		fd;
	char	**final_map;

	nbr_line = count_line(str);
	fd = open(str, O_RDONLY);
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
	if ((*game)->finalmap[y][x] == '0')
	{
		mlx_put_image_to_window((*game)->mlx,
			(*game)->win, (*game)->img_ground, x * 48, y * 48);
	}
	if ((*game)->finalmap[y][x] == 'P')
		player_draw(game, x, y);
	if ((*game)->finalmap[y][x] == 'C')
	{
		(*game)->nbr_item++;
		mlx_put_image_to_window((*game)->mlx,
			(*game)->win, (*game)->img_item, x * 48, y * 48);
	}
	if ((*game)->finalmap[y][x] == 'E')
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
