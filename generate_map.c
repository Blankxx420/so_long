/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:10:35 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/22 12:41:43 by brguicho         ###   ########.fr       */
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
	char	*tmp;

	i = 0;
	tmp = ft_strdup("");
	while (i < nbr_line)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\n')
		{
			free(tmp);
			free(line);
			break ;
		}
		tmp = ft_strjoinf(tmp, line);
		free(line);
		i++;
	}
	final_map = ft_split(tmp, '\n');
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
