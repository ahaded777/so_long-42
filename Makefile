NAME = so_long

#SRCS_OBJS
SRCS = $(PATH_SRCS)/so_long.c $(PATH_SRCS)/free_map.c $(PATH_SRCS)/close_window.c \
	$(PATH_SRCS_CHMPS)/check_map.c $(PATH_SRCS_CHMPS)/check_map_utils.c $(PATH_SRCS_CHMPS)/check_elements.c \
	$(PATH_SRCS_CHPLAY)/check_player.c $(PATH_SRCS_CHPLAY)/read_maps.c 
OBJS = $(SRCS:.c=.o)

#SRCS_BONUS
SRCS_BONUS = $(PATH_SRCS_BONUS)/so_long_bonus.c $(PATH_SRCS_BONUS)/free_map_bonus.c $(PATH_SRCS_BONUS)/close_window_bonus.c \
	$(PATH_SRCS_CHMPS_BONUS)/check_map_bonus.c $(PATH_SRCS_CHMPS_BONUS)/check_map_utils_bonus.c $(PATH_SRCS_CHMPS_BONUS)/check_elements_bonus.c \
	$(PATH_SRCS_CHPLAY_BONUS)/check_player_bonus.c $(PATH_SRCS_CHPLAY_BONUS)/read_maps_bonus.c 
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

#GET_NEXT_LINE_SRC_OBJS
SRC_GET_LINE = $(PATH_GET_LINE)/get_next_line.c $(PATH_GET_LINE)/get_next_line_utils.c
OBJS_GET_LINE = $(SRC_GET_LINE:.c=.o)

#SRCS_FOLDER
PATH_SRCS = ./srcs
PATH_SRCS_CHMPS = ./srcs/check_maps
PATH_SRCS_CHPLAY = ./srcs/check_player_remap

#SRCS_FOLDER_BONUS
PATH_SRCS_BONUS = ./srcs_bonus
PATH_SRCS_CHMPS_BONUS = ./srcs_bonus/check_maps_bonus
PATH_SRCS_CHPLAY_BONUS = ./srcs_bonus/check_player_remap_bonus


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

bonus: so_long_bonus

so_long_bonus: $(OBJS_BONUS) $(OBJS_GET_LINE)
	make -C $(MLX_DIR)
	make -C $(PATH_LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLX) $(LIBS) $(LIBFT_AR) $(OBJS_GET_LINE) -o $(NAME) 


clean:
	make clean -C $(MLX_DIR)
	make clean -C $(PATH_LIBFT)
	rm -f $(OBJS_GET_LINE)
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	make fclean -C $(PATH_LIBFT) 
	rm -f $(NAME)

re: fclean all
