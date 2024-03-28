/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:21:21 by brguicho          #+#    #+#             */
/*   Updated: 2024/03/21 10:48:24 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_img(t_game **game)
{
	(*game)->img_player = mlx_xpm_file_to_image((*game)->mlx,
			"asset/player_down.xpm", &(*game)->img_width, &(*game)->img_height);
	if (!(*game)->img_player)
		return (1);
	(*game)->img_wall = mlx_xpm_file_to_image((*game)->mlx,
			"asset/wall.xpm", &(*game)->img_width, &(*game)->img_height);
	if (!(*game)->img_wall)
		return (1);
	(*game)->img_item = mlx_xpm_file_to_image((*game)->mlx,
			"asset/item.xpm", &(*game)->img_width, &(*game)->img_height);
	if (!(*game)->img_item)
		return (1);
	(*game)->img_ground = mlx_xpm_file_to_image((*game)->mlx,
			"asset/ground.xpm", &(*game)->img_width, &(*game)->img_height);
	if (!(*game)->img_ground)
		return (1);
	(*game)->img_exit = mlx_xpm_file_to_image((*game)->mlx,
			"asset/exit.xpm", &(*game)->img_width, &(*game)->img_height);
	if (!(*game)->img_exit)
		return (1);
	return (0);
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
	(*game)->win = mlx_new_window((*game)->mlx,
			(*game)->width * 48, (*game)->heigth * 48, "So_long");
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
	game->finalmap = generate_map(str);
	if (!game->finalmap)
		return (NULL);
	count_item_get_player_pos(&game, game->finalmap);
	game->copy_map = generate_map(str);
	if (!game->copy_map)
		return (NULL);
	game->copy_map2 = generate_map(str);
	if (!game->copy_map2)
		return (NULL);
	return (game);
}

int	gameplay(t_game *game, char *str)
{
	game->heigth = count_line(str);
	game->width = ft_strlen(game->finalmap[0]);
	if (init_window(&game) == 1)
		return (1);
	if (init_img(&game) == 1)
		return (1);
	display_map(&game);
	mlx_hook(game->win, 2, 1L << 0, key_close_game, &game);
	mlx_key_hook(game->win, key_movement, &game);
	mlx_hook(game->win, 17, 0L, close_game, &game);
	mlx_loop(game->mlx);
	return (0);
}
