/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:20:25 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/18 14:19:31 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game		*game;
	
	game = malloc(sizeof(t_game));
	game->x_player = 0;
	game->y_player = 0;
	game->nbr_item = 0;
	game->inventory = 0;
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
	init_img(&game);
	display_map(&game);
	mlx_hook(game->win, 2, 1L<<0, key_close_game, &game);
	mlx_key_hook(game->win, key_movement, &game);
	mlx_hook(game->win, 17, 0L, close_game, &game);
	mlx_loop(game->mlx);
	return (0);
}