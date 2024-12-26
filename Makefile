NAME = so_long

#SRCS_OBJS
SRCS = so_long.c free_map.c close_window.c errors.c initialize.c \
	check_map.c check_map_utils.c check_elements.c \
	check_player.c read_maps.c check_player_ul.c
OBJS = $(SRCS:.c=.o)

#SRCS_BONUS
SRCS_BONUS = check_map_bonus.c check_map_utils_bonus.c check_player_bonus.c initialize_bonus.c \
	check_player_ul_bonus.c close_window_bonus.c errors_bonus.c check_elements_bonus.c initialize_ul_bonus.c \
	free_map_bonus.c read_maps_bonus.c so_long_bonus.c ft_animations_bonus.c so_long_textures_bonus.c ft_animations_ul_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

#GET_NEXT_LINE_SRC_OBJS
SRC_GET_LINE = $(PATH_GET_LINE)/get_next_line.c $(PATH_GET_LINE)/get_next_line_utils.c
OBJS_GET_LINE = $(SRC_GET_LINE:.c=.o)


#GET_NEXT_LINE
PATH_GET_LINE = $(PATH_LIBFT)/get_next_line

#LIBFT
PATH_LIBFT = ./libft
LIBFT_AR = $(PATH_LIBFT)/libft.a

#PRINTF
PATH_PRINTF = $(PATH_LIBFT)/printf
PRINTF_AR = $(PATH_PRINTF)/libftprintf.a

#MINILIBX
LIBS =  -lmlx -lXext -lX11

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_GET_LINE)
	@make -C $(PATH_LIBFT)
	@make -C $(PATH_PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LIBFT_AR) $(PRINTF_AR) $(OBJS_GET_LINE) -o $(NAME) 

bonus: so_long_bonus

so_long_bonus: $(OBJS_BONUS) $(OBJS_GET_LINE)
	@make -C $(PATH_LIBFT)
	@make -C $(PATH_PRINTF)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) $(LIBFT_AR) $(PRINTF_AR) $(OBJS_GET_LINE) -o $(NAME) 


clean:
	@make clean -C $(PATH_LIBFT)
	@make clean -C $(PATH_PRINTF)
	@rm -f $(OBJS_GET_LINE)
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)

fclean: clean
	@make fclean -C $(PATH_LIBFT) 
	@make fclean -C $(PATH_PRINTF)
	@rm -f $(NAME)

re: fclean all
