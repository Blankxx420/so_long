# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 09:01:23 by brguicho          #+#    #+#              #
#    Updated: 2024/04/19 09:40:38 by brguicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -g -Wall -Werror -Wextra

SRCS = main.c \
		exit.c \
		generate_map.c \
		render_player.c \
		init.c \
		init2.c \
		movement.c \
		checker_map.c \
		checker_map2.c \
		checker_map3.c \
		utils.c \
		utils2.c

OBJS = $(SRCS:.c=.o)


LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX_DIR = mlx_linux
MINILIBX = $(MINILIBX_DIR)/libmlx_Linux.a
INCLUDES = -I $(MINILIBX_DIR) -I $(LIBFT_DIR)
LDFLAGS =  -L$(MINILIBX_DIR) -lmlx_Linux -L$(LIBFT_DIR) -lft -lXext -lX11 -lm -lz

all: $(NAME)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)
	
$(NAME): $(MINILIBX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(MINILIBX) -o $(NAME) $(CFLAGS) $(INCLUDES) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean :
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)
	rm -rf $(OBJS)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re