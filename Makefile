NAME = Game
CC = clang
CFLAGS =  -g -Wall -Werror -Wextra

SRCS = main.c

OBJS = $(SRCS:.c=.o)

MINILIBX_DIR = mlx_linux
MINILIBX = $(MINILIBX_DIR)/libmlx_Linux.a
INCLUDES = -I $(MINILIBX_DIR)
LDFLAGS =  -L$(MINILIBX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

all: $(NAME)

$(MINILIBX):
	make -C $(MINILIBX_DIR)
	
$(NAME): $(MINILIBX) $(OBJS)
	$(CC) $(OBJS) $(MINILIBX) -o $(NAME) $(CFLAGS) $(INCLUDES) $(LDFLAGS)
  
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re