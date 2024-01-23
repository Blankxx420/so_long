/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:21:21 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/23 12:12:56 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_game **game)
{
	(*game)->img_player = mlx_xpm_file_to_image((*game)->mlx, "asset/player_down.xpm", &(*game)->img_width, &(*game)->img_height);
	(*game)->img_wall = mlx_xpm_file_to_image((*game)->mlx, "asset/wall.xpm", &(*game)->img_width, &(*game)->img_height);
	(*game)->img_item = mlx_xpm_file_to_image((*game)->mlx, "asset/item.xpm", &(*game)->img_width, &(*game)->img_height);
	(*game)->img_ground = mlx_xpm_file_to_image((*game)->mlx, "asset/ground.xpm", &(*game)->img_width, &(*game)->img_height);
	(*game)->img_exit = mlx_xpm_file_to_image((*game)->mlx, "asset/exit.xpm", &(*game)->img_width, &(*game)->img_height);
}

void	init_vars(t_game **game)
{
	
	(*game)->x_player = 0;
	(*game)->y_player = 0;
	(*game)->nbr_item = 0;
	(*game)->inventory = 0;
	(*game)->nbr_move = 0;
}

int	init_window(t_game **game)
{
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
		return (1);
	(*game)->win = mlx_new_window((*game)->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	if (!(*game)->win)
	{
		free((*game)->mlx);
		return (1);
	}
	return (0);
}

t_game	*init(char *str)
{
	t_game		*game;
	
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	init_vars(&game);
	init_window(&game);
	init_img(&game);
	game->finalmap = generate_map(str);
	display_map(&game);
	return (game);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 1L<<0, key_close_game, &game);
	mlx_key_hook(game->win, key_movement, &game);
	mlx_hook(game->win, 17, 0L, close_game, &game);
	mlx_loop(game->mlx);
}