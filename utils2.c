/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:27:16 by brguicho          #+#    #+#             */
/*   Updated: 2024/04/19 09:32:46 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_all_image(t_game **game)
{
	if ((*game)->img_wall)
		mlx_destroy_image((*game)->mlx, (*game)->img_wall);
	if ((*game)->img_item)
		mlx_destroy_image((*game)->mlx, (*game)->img_item);
	if ((*game)->img_ground)
		mlx_destroy_image((*game)->mlx, (*game)->img_ground);
	if ((*game)->img_exit)
		mlx_destroy_image((*game)->mlx, (*game)->img_exit);
	if ((*game)->img_player_down)
		mlx_destroy_image((*game)->mlx, (*game)->img_player_down);
	if ((*game)->img_player_up)
		mlx_destroy_image((*game)->mlx, (*game)->img_player_up);
	if ((*game)->img_player_left)
		mlx_destroy_image((*game)->mlx, (*game)->img_player_left);
	if ((*game)->img_player_right)
		mlx_destroy_image((*game)->mlx, (*game)->img_player_right);
}