/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:20:25 by brguicho          #+#    #+#             */
/*   Updated: 2024/03/28 14:53:33 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game		*game;

	if (argc == 2 && check_argv(argv[1]))
	{
		game = init(argv[1]);
		if (!game)
			return (1);
		if (check_map(&game, argv[1]))
		{
			if (gameplay(game, argv[1]) == 1)
			{
				ft_free_all_tab(game);
				free(game);
			}
		}
		else
		{
			ft_free_all_tab(game);
			free(game);
		}
	}
	else
		ft_printf("%s\n", "wrong number of argument expected 1");
	return (0);
}
