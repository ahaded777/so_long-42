NAME = so_long

#SRC_OBJS
SRCS = $(PATH_SRCS)/so_long.c $(PATH_SRCS)/free_map.c $(PATH_SRCS)/close_window.c \
	$(PATH_SRCS_CHMPS)/check_map.c $(PATH_SRCS_CHMPS)/check_map_utils.c $(PATH_SRCS_CHMPS)/check_elements.c \
	$(PATH_SRCS_CHPLAY)/check_player.c $(PATH_SRCS_CHPLAY)/read_maps.c 
OBJS = $(SRCS:.c=.o)

#GET_NEXT_LINE_SRC_OBJS
SRC_GET_LINE = $(PATH_GET_LINE)/get_next_line.c $(PATH_GET_LINE)/get_next_line_utils.c
OBJS_GET_LINE = $(SRC_GET_LINE:.c=.o)

#SRCS_FOLDER
PATH_SRCS = ./srcs
PATH_SRCS_CHMPS = ./srcs/check_maps
PATH_SRCS_CHPLAY = ./srcs/check_player_remap

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
