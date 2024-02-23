/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:20:25 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/23 13:14:06 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game		*game;

	if (argc == 2 && check_argv(argv[1]))
	{
		game = init(argv[1]);
		if (check_map(&game, argv[1]))
		{
			ft_free_tab(game->copy_map);
			ft_free_tab(game->copy_map2);
			gameplay(game, argv[1]);
		}
		else
		{
			ft_free_tab(game->copy_map);
			ft_free_tab(game->copy_map2);
			ft_free_tab(game->finalmap);
			free(game);
		}
	}
	else
		ft_printf("%s\n", "wrong number of argument expected 1");
	return (0);
}
