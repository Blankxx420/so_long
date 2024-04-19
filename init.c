/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:21:21 by brguicho          #+#    #+#             */
/*   Updated: 2024/04/19 20:57:33 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_img(t_game *game)
{
	if (init_img_player(&game) == 1)
		return (1);
	if (init_img_tiles(&game) == 1)
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
	(*game)->img_player_down = NULL;
	(*game)->img_player_up = NULL;
	(*game)->img_player_left = NULL;
	(*game)->img_player_right = NULL;
	(*game)->img_wall = NULL;
	(*game)->img_ground = NULL;
	(*game)->img_item = NULL;
	(*game)->img_exit = NULL;
}

int	init_window(t_game **game)
{
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
		return (1);
	(*game)->win = mlx_new_window((*game)->mlx,
			(*game)->width * 48, (*game)->heigth * 48, "So_long");
	if (!(*game)->win)
		return (1);
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
	{
		free(game);
		return (NULL);
	}
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
	{
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
			mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (1);
	}
	if (init_img(game) == 1)
	{
		ft_free_all_image(&game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (1);
	}
	display_map(&game);
	mlx_hook(game->win, 2, 1L << 0, key_close_game, &game);
	mlx_key_hook(game->win, key_movement, &game);
	mlx_hook(game->win, 17, 0L, close_game, &game);
	mlx_loop(game->mlx);
	return (0);
}
