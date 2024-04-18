/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:47:51 by brguicho          #+#    #+#             */
/*   Updated: 2024/04/18 22:25:20 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_img_player(t_game **game)
{
	(*game)->img_player_down = mlx_xpm_file_to_image((*game)->mlx,
			"asset/player_down.xpm", &(*game)->img_width, &(*game)->img_height);
	if (!(*game)->img_player_down)
		return (1);
	(*game)->img_player_up = mlx_xpm_file_to_image((*game)->mlx,
			"asset/player_up.xpm", &(*game)->img_width, &(*game)->img_height);
	if (!(*game)->img_player_up)
		return (1);
	(*game)->img_player_left = mlx_xpm_file_to_image((*game)->mlx,
			"asset/player_left.xpm", &(*game)->img_width, &(*game)->img_height);
	if (!(*game)->img_player_left)
		return (1);
	(*game)->img_player_right = mlx_xpm_file_to_image((*game)->mlx,
			"asset/player_right.xpm",
			&(*game)->img_width, &(*game)->img_height);
	if (!(*game)->img_player_right)
		return (1);
	return (0);
}

int	init_img_tiles(t_game **game)
{
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
