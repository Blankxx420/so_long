/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:20:25 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/17 14:55:02 by blankx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game		*game;
	
	game = malloc(sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	if (!game->win)
	{
		free(game->mlx);
		return (1);
	}
	game->finalmap = generate_map("map.ber");
	display_map(&game);
	mlx_key_hook(game->win, key_close_game, game);
	mlx_hook(game->win, 17, 0L, close_game, game);
	mlx_loop(game->mlx);
	return (0);
}