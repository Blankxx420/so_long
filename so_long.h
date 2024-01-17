/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:19:02 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/16 14:54:00 by blankx           ###   ########.fr       */
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
typedef struct	s_vars {
	void		*mlx;
	void		*win;
	char		**finalmap;
}				t_vars;

typedef struct	s_sprite {
	void 	*img;
	char	*path;
	int		width;
	int		height;
}				t_sprite;

int 	close_game(t_vars *vars);
int		key_close_game(int keycode, t_vars *vars);
int		count_line(char *str);
char	**generate_map(char *str);
void 	display_map(t_vars **vars);
void    render_ground(t_vars **vars, int x, int y);
void    render_wall(t_vars **vars, int x, int y);
void    render_item(t_vars **vars, int x, int y);
void    render_player_down(t_vars **vars, int x, int y);

#endif