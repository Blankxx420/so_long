/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:19:02 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/31 13:58:11 by brguicho         ###   ########.fr       */
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
	char		**copy_map;
	int			img_width;
	int			img_height;
	int			nbr_item;
	int			nbr_line;
	int			nbr_char;
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


// initialization function 
t_game	*init();
void	init_vars(t_game **game);
void	init_img(t_game **game);
char	**generate_map(char *str);
void 	display_map(t_game **game);
int		count_line(char *str);
void	gameplay(t_game *game);

// hook function
int 	close_game(t_game **game);
int		key_movement(int keycode, t_game **game);
int		key_close_game(int keycode, t_game **game);

//handle player movement function
void	player_draw(t_game **game, int x, int y);
void 	update_player_img(char key, t_game **game);
void 	move_up(t_game **game);
void 	move_down(t_game **game);
void 	move_left(t_game **game);
void 	move_right(t_game **game);

//checking function for maps
int		is_end(char **final_map);
int 	char_is_valid(char c);
int		is_rectangle(char **final_map, char *map);
int		check_map_char(char **final_map, int nbr_item);
int		map_is_close(char **final_map, int nbrline);
char	**ft_spread(char **final_map, int x, int y, int nbr_line);
int		check_map(t_game **game, char *argv);
void    count_item_get_player_pos(t_game *game, char **finalmap);
void 	set_player_position(t_game *game, int x, int y);
#endif