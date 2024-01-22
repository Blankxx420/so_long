/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:19:02 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/22 11:14:11 by brguicho         ###   ########.fr       */
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
	int			nbr_item;
	int			inventory;
	int			x_player;
	int			y_player;
	int			nbr_move;
	void 		*img_player;
	void 		*img_wall;
	void 		*img_item;
	void 		*img_ground;
	void 		*img_exit;
}				t_game;



int 	close_game(t_game **game);
int		key_close_game(int keycode, t_game **game);
int		count_line(char *str);
char	**generate_map(char *str);
void 	display_map(t_game **game);
void	init_img(t_game **game);
void	init_vars(t_game **game);
t_game	*init();
void	gameplay(t_game *game);
void	player_draw(t_game **game, int x, int y);
void 	update_player_img(char key, t_game **game);
int		key_movement(int keycode, t_game **game);
void 	move_up(t_game **game);
void 	move_down(t_game **game);
void 	move_left(t_game **game);
void 	move_right(t_game **game);

#endif