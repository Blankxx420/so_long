/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:21:21 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/18 12:34:32 by brguicho         ###   ########.fr       */
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