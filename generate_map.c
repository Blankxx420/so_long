/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:54:26 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/03 13:23:02 by blankx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	printlinked_list(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		printf("%s", (char*)tmp->content);
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
		return ;
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

int main()
{
	generate_map();
	return (0);
}