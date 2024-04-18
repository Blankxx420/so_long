/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:51:36 by brguicho          #+#    #+#             */
/*   Updated: 2024/04/05 22:03:51 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	free_stock(char *stock[1024])
{
	int	i;

	i = -1;
	while (++i < 1024)
		free(stock[i]);
}

int	check_line_and_stock(char *line, char **stock, int fd)
{
	if (line && !*line && ft_strlen(stock[fd]) == 0)
	{
		free(line);
		free(stock[fd]);
		stock[fd] = NULL;
		line = NULL;
		return (1);
	}
	return (0);
}
