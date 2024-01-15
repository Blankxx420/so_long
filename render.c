/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:37:24 by blankx            #+#    #+#             */
/*   Updated: 2024/01/15 13:34:44 by blankx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    render_ground(t_vars **vars, int x, int y)
{
    t_sprite    img;
    t_vars      *ptr;

    ptr = *vars;
    img.path = "asset/ground.xpm";
    img.img = mlx_xpm_file_to_image(ptr->mlx, img.path, &img.width, &img.height);
    mlx_put_image_to_window(ptr->mlx, ptr->win, img.img, x, y);
    mlx_destroy_image(ptr->mlx, img.img);
}
void    render_wall(t_vars **vars, int x, int y)
{
    t_sprite    img;
    t_vars      *ptr;

    ptr = *vars;
    img.path = "asset/wall.xpm";
    img.img= mlx_xpm_file_to_image(ptr->mlx, img.path, &img.width, &img.height);
    mlx_put_image_to_window(ptr->mlx, ptr->win, img.img, x, y);
    mlx_destroy_image(ptr->mlx, img.img);
}
void    render_player_down(t_vars **vars, int x, int y)
{
    t_sprite    img;
    t_vars      *ptr;

    ptr = *vars;
    img.path = "asset/ACharDown.xpm";
    img.img = mlx_xpm_file_to_image(ptr->mlx, img.path, &img.width, &img.height);
    mlx_put_image_to_window(ptr->mlx, ptr->win, img.img, x, y);
    mlx_destroy_image(ptr->mlx, img.img);
}

void    render_player_right(t_vars **vars, int x, int y)
{
    t_sprite    img;
    t_vars      *ptr;

    ptr = *vars;
    img.path = "asset/ACgarRight.xpm";
    img.img = mlx_xpm_file_to_image(ptr->mlx, img.path, &img.width, &img.height);
    mlx_put_image_to_window(ptr->mlx, ptr->win, img.img, x, y);
    mlx_destroy_image(ptr->mlx, img.img);
}

void    render_player_up(t_vars **vars, int x, int y)
{
    t_sprite    img;
    t_vars      *ptr;

    ptr = *vars;
    img.path = "asset/ACharUP.xpm";
    img.img = mlx_xpm_file_to_image(ptr->mlx, img.path, &img.width, &img.height);
    mlx_put_image_to_window(ptr->mlx, ptr->win, img.img, x, y);
    mlx_destroy_image(ptr->mlx, img.img);
}

void    render_player_left(t_vars **vars, int x, int y)
{
    t_sprite    img;
    t_vars      *ptr;

    ptr = *vars;
    img.path = "asset/ACharLeft.xpm";
    img.img = mlx_xpm_file_to_image(ptr->mlx, img.path, &img.width, &img.height);
    mlx_put_image_to_window(ptr->mlx, ptr->win, img.img, x, y);
    mlx_destroy_image(ptr->mlx, img.img);
}
void    render_item(t_vars **vars, int x, int y)
{
    t_sprite    img;
    t_vars      *ptr;

    ptr = *vars;
    img.path = "asset/crab.xpm";
    img.img = mlx_xpm_file_to_image(ptr->mlx, img.path, &img.width, &img.height);
    mlx_put_image_to_window(ptr->mlx, ptr->win, img.img, x, y);
    mlx_destroy_image(ptr->mlx, img.img);
}