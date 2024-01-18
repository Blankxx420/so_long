/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:37:24 by blankx            #+#    #+#             */
/*   Updated: 2024/01/17 15:28:57 by blankx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    render_ground(t_game **game, int x, int y)
{
    t_game      *ptr;

    ptr = *game;
    ptr->img_ground = mlx_xpm_file_to_image(ptr->mlx, "asset/ground.xpm", &ptr->img_width, &ptr->img_height);
    mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_ground, x, y);
    mlx_destroy_image(ptr->mlx, ptr->img_ground);
}

void    render_wall(t_game **game, int x, int y)
{
    t_game      *ptr;

    ptr = *game;
    ptr->img_wall = mlx_xpm_file_to_image(ptr->mlx, "asset/wall.xpm", &ptr->img_width, &ptr->img_height);
    mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_wall, x, y);
    mlx_destroy_image(ptr->mlx, ptr->img_wall);
}

void    render_item(t_game **game, int x, int y)
{
    t_game      *ptr;

    ptr = *game;
    ptr->img_item = mlx_xpm_file_to_image(ptr->mlx, "asset/crab.xpm", &ptr->img_width, &ptr->img_height);
    mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_item, x, y);
    mlx_destroy_image(ptr->mlx, ptr->img_item);
}

void    render_exit(t_game **game, int x, int y)
{
    t_game      *ptr;

    ptr = *game;
    ptr->img_exit = mlx_xpm_file_to_image(ptr->mlx, "asset/exit.xpm", &ptr->img_width, &ptr->img_height);
    mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img_exit, x, y);
    mlx_destroy_image(ptr->mlx, ptr->img_exit);
}