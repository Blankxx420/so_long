/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:19:02 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/07 13:32:52 by blankx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

# define WINDOW_WIDTH 12
# define WINDOW_HEIGHT 48 
# define WINDOW 48 * 12
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

#endif