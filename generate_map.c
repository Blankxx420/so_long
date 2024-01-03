/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:54:26 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/03 18:01:36 by blankx           ###   ########.fr       */
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
	final_map = malloc(sizeof(t_list));
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
		map = ft_lstnew(str);
		ft_lstadd_back(&final_map, map);
		line = get_next_line(fd);
	}
	close(fd);
	printlinked_list(&final_map);
	return (final_map);
}


void	display_map(t_list **final_map)
{
	int i;
	t_list *tmp;

	tmp = *final_map;
	while (tmp)
	{
		while (tmp->content)
		{
			if (tmp->content[i] == '1')
				render_wall();
			if (tmp->content[i] == '0')
				render_grond();
			if (tmp->content[i] == 'P')
				render_player();
			if (tmp->content[i] == 'C')
				render_item();
			if (tmp->content[i] == 'E')
				render_exit();
			i++;
		}
		tmp = tmp->next;
	}
}

int main()
{
	generate_map();
	return (0);
}