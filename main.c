/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:20:25 by brguicho          #+#    #+#             */
/*   Updated: 2023/12/21 13:50:47 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_close(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		mlx_loop_end(vars->mlx);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_vars	*vars;
	
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (1);
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "Hello world!");
	if (!vars->win)
	{
		free(vars->mlx);
		return (1);
	}
	mlx_key_hook(vars->win, key_close, vars);
	mlx_loop(vars->mlx);
	return (0);
}