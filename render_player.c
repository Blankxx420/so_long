/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:20:28 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/18 11:56:34 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void update_player_img(char key, t_game **game)
{
	t_game *tmp;
	
	tmp = (*game);
	if (key == 'w')
		tmp->img_player = mlx_xpm_file_to_image(tmp->mlx, "asset/player_up.xpm", &tmp->img_width, &tmp->img_height);
	if (key == 's')
		tmp->img_player = mlx_xpm_file_to_image(tmp->mlx, "asset/player_down.xpm", &tmp->img_width, &tmp->img_height);
	if (key == 'a')
		tmp->img_player = mlx_xpm_file_to_image(tmp->mlx, "asset/player_left.xpm", &tmp->img_width, &tmp->img_height);
	if (key == 'd')
		tmp->img_player = mlx_xpm_file_to_image(tmp->mlx, "asset/player_right.xpm", &tmp->img_width, &tmp->img_height);
}

void	player_draw(t_game **game, int x, int y)
{
	if ((*game)->x_player && (*game)->y_player)
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img_ground,(*game)->x_player * 48, (*game)->y_player * 48);
	(*game)->x_player = x;
	(*game)->y_player = y; 
	mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img_player, x * 48, y * 48);
}
