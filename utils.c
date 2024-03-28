/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:35:28 by brguicho          #+#    #+#             */
/*   Updated: 2024/03/28 14:58:23 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_position(t_game **game, int x, int y)
{
	(*game)->x_player = x;
	(*game)->y_player = y;
}

void	count_item_get_player_pos(t_game **game, char **finalmap)
{
	int	i;
	int	j;

	i = 0;
	while (finalmap[i])
	{
		j = 0;
		while (finalmap[i][j])
		{
			if (finalmap[i][j] == 'C')
				(*game)->nbr_item++;
			if (finalmap[i][j] == 'P')
				set_player_position(game, j, i);
			j++;
		}
		i++;
	}
}

char	*get_line_join(int fd, char *tmp)
{
	char	*line;

	line = get_next_line(fd);
	if (!line || line[0] == '\n')
	{
		free(tmp);
		free(line);
		return (NULL);
	}
	tmp = ft_strjoinf(tmp, line);
	if (!tmp)
	{
		free(tmp);
		free(line);
		return (NULL);
	}
	free(line);
	return (tmp);
}

void	ft_free_all_tab(t_game *game)
{
	ft_free_tab(game->copy_map);
	ft_free_tab(game->copy_map2);
	ft_free_tab(game->finalmap);
}
