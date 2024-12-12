NAME = so_long

#SRC_OBJS
SRC = $(PATH_SRC)/so_long.c
OBJS = $(SRC:.c=.o)

#GET_NEXT_LINE_SRC_OBJS
SRC_GET_LINE = $(PATH_GET_LINE)/get_next_line.c $(PATH_GET_LINE)/get_next_line_utils.c
OBJS_GET_LINE = $(SRC_GET_LINE:.c=.o)

#SRC_FOLDER
PATH_SRC = ./src

#GET_NEXT_LINE
PATH_GET_LINE = ./get_next_line

#LIBFT
PATH_LIBFT = ./libft
LIBFT_AR = $(PATH_LIBFT)/libft.a

#MINILIBX
MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_GET_LINE)
	make -C $(MLX_DIR)
	make -C $(PATH_LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBS) $(LIBFT_AR) $(OBJS_GET_LINE) -o $(NAME) 

clean:
	make clean -C $(MLX_DIR)
	make clean -C $(PATH_LIBFT)
	rm -f $(OBJS_GET_LINE)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(PATH_LIBFT) 
	rm -f $(NAME)

re: fclean all
