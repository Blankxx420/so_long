NAME = game
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

SRCS = main.c \
		exit.c \
		generate_map.c \
		render_player.c \
		init.c \
		movement.c \
		checker_map.c \
		checker_map2.c \
		checker_map3.c \
		utils.c

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
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re