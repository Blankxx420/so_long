/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:54:26 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/15 13:52:19 by blankx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	printlinked_list(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		printf("%s", tmp->content);
		tmp = tmp->next;
	}
}

t_list	*generate_map(void)
{
    char	*line;
	char 	*str;
    int		fd;
	t_list	*final_map;
	t_list	*map;
	
	fd = open("map.ber", O_RDONLY);
	final_map = ft_calloc(1 , sizeof(t_list));
	if (!final_map)
		return (NULL);
	line = get_next_line(fd);
	str = ft_strdup(line);
	final_map->content = str;
	free(line);
	line = get_next_line(fd);
    while (line != NULL)
	{	str = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		map = ft_lstnew(str);
		ft_lstadd_back(&final_map, map);
			
	}
	close(fd);
	return (final_map);
}


void	display_map(t_list **final_map, t_vars **vars)
{
	int x;
	int y;
	t_list *tmp;

	tmp = *final_map;
	y = 0;
	while (tmp)
	{	x = 0;
		while (tmp->content[x])
		{
			if (tmp->content[x] == '1')
				render_wall(vars, x * 48, y * 48);
			if (tmp->content[x] == '0')
				render_ground(vars, x * 48, y * 48);
			if (tmp->content[x] == 'P')
				render_player_down(vars, x * 48, y * 48);
			if (tmp->content[x] == 'C')
				render_item(vars, x * 48, y * 48);
			if (tmp->content[x] == 'E')
				render_wall(vars, x * 48, y * 48);
			x++;
		}
		tmp = tmp->next;
		y++;
	}
}
