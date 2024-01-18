/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:19:02 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/17 16:28:37 by blankx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

# define WINDOW_WIDTH 15 * 48
# define WINDOW_HEIGHT 10 * 48
typedef struct	s_game {
	void		*mlx;
	void		*win;
	char		**finalmap;
	int			img_width;
	int			img_height;
	int			inventory;
	void 		*img_player;
	void 		*img_wall;
	void 		*img_item;
	void 		*img_ground;
	void 		*img_exit;
}				t_game;



int 	close_game(t_game *game);
int		key_close_game(int keycode, t_game *game);
int		count_line(char *str);
char	**generate_map(char *str);
void 	display_map(t_game **game);
void    render_ground(t_game **game, int x, int y);
void    render_wall(t_game **game, int x, int y);
void    render_item(t_game **game, int x, int y);
void    render_exit(t_game **game, int x, int y);

#endif