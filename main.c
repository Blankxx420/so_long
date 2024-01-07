/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:20:25 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/07 13:32:03 by blankx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_vars	*vars;
	t_sprite	img;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (1);
	vars->win = mlx_new_window(vars->mlx, WINDOW, WINDOW, "Hello world!");
	if (!vars->win)
	{
		free(vars->mlx);
		return (1);
	}
	img.path = "asset/ground.xpm";
	img.img = mlx_xpm_file_to_image(vars->mlx, img.path, &img.width, &img.height);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 48);
	mlx_key_hook(vars->win, key_close_game, vars);
	mlx_hook(vars->win, 17, 0L, close_game, vars);
	mlx_loop(vars->mlx);
	return (0);
}