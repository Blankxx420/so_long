/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:03:34 by blankx            #+#    #+#             */
/*   Updated: 2024/03/28 14:53:16 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game **game)
{
	mlx_destroy_image((*game)->mlx, (*game)->img_player);
	mlx_destroy_image((*game)->mlx, (*game)->img_wall);
	mlx_destroy_image((*game)->mlx, (*game)->img_ground);
	mlx_destroy_image((*game)->mlx, (*game)->img_item);
	mlx_destroy_image((*game)->mlx, (*game)->img_exit);
	mlx_destroy_window((*game)->mlx, (*game)->win);
	mlx_destroy_display((*game)->mlx);
	ft_free_all_tab((*game));
	free((*game)->mlx);
	free(*game);
	exit(0);
	return (0);
}

int	key_close_game(int keycode, t_game **game)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_image((*game)->mlx, (*game)->img_player);
		mlx_destroy_image((*game)->mlx, (*game)->img_wall);
		mlx_destroy_image((*game)->mlx, (*game)->img_ground);
		mlx_destroy_image((*game)->mlx, (*game)->img_item);
		mlx_destroy_image((*game)->mlx, (*game)->img_exit);
		mlx_destroy_window((*game)->mlx, (*game)->win);
		mlx_destroy_display((*game)->mlx);
		ft_free_all_tab((*game));
		free((*game)->mlx);
		free(*game);
		exit(0);
	}
	return (0);
}
