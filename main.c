/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:20:25 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/01 12:52:17 by blankx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int close_game(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars);
	exit(0);
	return (0);
}

int	key_close_game(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		mlx_loop_end(vars->mlx);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		free(vars);
		exit(0);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_vars	*vars;
	t_data	img;

	
	img.bits_per_pixel = 1000;
	img.line_length = 100;
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (1);
	vars->win = mlx_new_window(vars->mlx, WINDOW_HEIGHT, WINDOW_WIDTH, "Hello world!");
	if (!vars->win)
	{
		free(vars->mlx);
		return (1);
	}
	img.img = mlx_new_image(vars->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 48, 48, 0x00FF0000);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 48, 48);
	mlx_key_hook(vars->win, key_close_game, vars);
	mlx_hook(vars->win, 17, 0L, close_game, vars);
	mlx_loop(vars->mlx);
	return (0);
}