NAME = so_long

#SRCS_OBJS
SRCS = so_long.c free_map.c close_window.c errors.c \
	check_map.c check_map_utils.c check_elements.c \
	check_player.c read_maps.c check_player_ul.c
OBJS = $(SRCS:.c=.o)

#SRCS_BONUS
# SRCS_BONUS = $(PATH_SRCS_BONUS)/so_long_bonus.c $(PATH_SRCS_BONUS)/free_map_bonus.c $(PATH_SRCS_BONUS)/close_window_bonus.c \
# 	$(PATH_SRCS_CHMPS_BONUS)/check_map_bonus.c $(PATH_SRCS_CHMPS_BONUS)/check_map_utils_bonus.c $(PATH_SRCS_CHMPS_BONUS)/check_elements_bonus.c \
# 	$(PATH_SRCS_CHPLAY_BONUS)/check_player_bonus.c $(PATH_SRCS_CHPLAY_BONUS)/read_maps_bonus.c $(PATH_SRCS_CHPLAY_BONUS)/check_player_ul_bonus.c 
# 	#$(PATH_SRCS_ELEME_ANIM_BONUS)/coin_animations_bonus.c
# OBJS_BONUS = $(SRCS_BONUS:.c=.o)

#GET_NEXT_LINE_SRC_OBJS
SRC_GET_LINE = $(PATH_GET_LINE)/get_next_line.c $(PATH_GET_LINE)/get_next_line_utils.c
OBJS_GET_LINE = $(SRC_GET_LINE:.c=.o)


#GET_NEXT_LINE
PATH_GET_LINE = $(PATH_LIBFT)/get_next_line

#LIBFT
PATH_LIBFT = ./libft
LIBFT_AR = $(PATH_LIBFT)/libft.a

#MINILIBX
LIBS =  -lmlx -lXext -lX11 -lm -lbsd 

CC = cc
CFLAGS = -Wall -Wextra -Werror  -g3 -fsanitize=address 

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_GET_LINE)
	make -C $(PATH_LIBFT)
	$(CC) $(CFLAGS) $(OBJS)  $(LIBS) $(LIBFT_AR) $(OBJS_GET_LINE) -o $(NAME) 

# bonus: so_long_bonus

# so_long_bonus: $(OBJS_BONUS) $(OBJS_GET_LINE)
# 	make -C $(PATH_LIBFT)
# 	$(CC) $(CFLAGS) $(OBJS_BONUS)  $(LIBS) $(LIBFT_AR) $(OBJS_GET_LINE) -o $(NAME) 


clean:
	make clean -C $(PATH_LIBFT)
	rm -f $(OBJS_GET_LINE)
	rm -f $(OBJS)
	# rm -f $(OBJS_BONUS)

fclean: clean
	make fclean -C $(PATH_LIBFT) 
	rm -f $(NAME)

re: fclean all
