/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:20:25 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/15 12:51:39 by blankx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_vars		*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (1);
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	if (!vars->win)
	{
		free(vars->mlx);
		return (1);
	}
	vars->finalmap = generate_map();
	display_map(&vars->finalmap, &vars);
	mlx_key_hook(vars->win, key_close_game, vars);
	mlx_hook(vars->win, 17, 0L, close_game, vars);
	mlx_loop(vars->mlx);
	return (0);
}