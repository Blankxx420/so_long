/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:19:02 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/09 15:40:41 by brguicho         ###   ########.fr       */
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
	void	*mlx;
	void	*win;
	
}				t_vars;

typedef struct	s_sprite {
	void 	*img;
	char	*path;
	int		width;
	int		height;
}				t_sprite;

int close_game(t_vars *vars);
int	key_close_game(int keycode, t_vars *vars);

t_list	*generate_map(void);
void	display_map(t_list **final_map, t_vars **vars);
void    render_item(t_vars **vars, int x, int y);
void    render_player(t_vars **vars, int x, int y);
void    render_wall(t_vars **vars, int x, int y);
void    render_ground(t_vars **vars, int x, int y);
#endif