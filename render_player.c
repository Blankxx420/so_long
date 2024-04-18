/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:20:28 by brguicho          #+#    #+#             */
/*   Updated: 2024/04/18 19:56:19 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_draw(t_game **game, int x, int y, void *img_player)
{
	int	pxl;

	pxl = 48;
	if ((*game)->x_player && (*game)->y_player)
		mlx_put_image_to_window((*game)->mlx, (*game)->win,
			(*game)->img_ground, (*game)->x_player * pxl,
			(*game)->y_player * pxl);
	(*game)->x_player = x;
	(*game)->y_player = y;
	mlx_put_image_to_window((*game)->mlx, (*game)->win,
		img_player, x * pxl, y * pxl);
}
