/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <aahaded@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:30:47 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/19 10:10:36 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./libft/get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./libft/printf/ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# define TILE_SIZE 64
# define ESC_KEY 65307
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define COUNT_IMAGE_ANIM 6
# define COUNT_IMAGE_PLAYER 2
# define COUNT_IMAGE_PLAYER_DOWN 2
# define COUNT_IMAGE_PLAYER_LEFT 1
# define COUNT_IMAGE_PLAYER_UP 2
# define COUNT_IMAGE_PLAYER_R 1
# define COUNT_IMAGE_ENEMY 3

typedef struct s_exit_coins
{
	int				num_exit;
	int				coins_;
}					t_exit_coins;

typedef struct s_render_index
{
	int				i;
	int				j;
}					t_render_index;

typedef struct s_player_move_and_data
{
	int				x;
	int				y;
	int				coins;
}					t_player_move;

typedef struct s_textures
{
	void			*wall;
	void			*floor;
	void			*player;
	void			*coin;
	void			*exit;

	void			*coin_frames[COUNT_IMAGE_ANIM];
	int				count_frames;
	int				coin_timer;

	void			*player_frames[COUNT_IMAGE_PLAYER];
	int				count_p_frames;
	void			*p_down_frames[COUNT_IMAGE_PLAYER_DOWN];
	int				count_pd_frames;
	void			*p_left_frames[COUNT_IMAGE_PLAYER_LEFT];
	int				count_pl_frames;
	void			*p_up_frames[COUNT_IMAGE_PLAYER_UP];
	int				count_pu_frames;
	void			*p_r_frames[COUNT_IMAGE_PLAYER_R];
	int				count_pr_frames;
	void			*p_en_frames[COUNT_IMAGE_ENEMY];
	int				count_en_frames;
	int				p_timer;
	char			*str;
	int				move_count;
}					t_textures;

typedef struct s_map_size
{
	int				len_x;
	int				len_y;
}					t_map_size;

typedef struct s_window
{
	void			*mlx;
	void			*mlx_win;
	char			**map;
	int				img_width;
	int				img_height;
	int				count_coins;
	int				x;
	int				y;
	t_player_move	*player;
	t_textures		textures;
	t_map_size		*map_size;
	t_render_index	index_door;
	t_exit_coins	*exit_coins;
}					t_window;

void				free_map(char **map);
void				print_message(char *message, int fd);
void				ft_check_map(char *filename);
char				**read_map(char *filename);
int					ft_check_wall_up(char **map);
int					close_window(void *par);
int					handle_keypress(int keycode, t_window *window);
void				size_map(t_window *window, t_map_size *map_size);
void				check_player_map(t_window window, t_player_move *player);
void				render_map(t_textures textures, t_window *window,
						t_player_move player);
void				ft_check_elements(char **map);
void				check_door_map(t_window *window);
void				check_player_map(t_window window, t_player_move *player);

void				ft_check_map_v1(char **map);
void				ft_check_map_walls(char **map);
void				ft_check_filename(char *filename);
void				load_textures_player(t_window *window,
						t_textures *textures);
void	load_textures_coins(t_window *window, t_textures *textures);
//void	load_textures_player_ul(t_window *window, t_textures *textures);
int					animation_coins(t_window *window);
int					animation_player(t_window *window);
int					all_animation(t_window *window);
int					animation_player_down(t_window *window);
int					animation_player_left(t_window *window);
int					animation_player_right(t_window *window);
int					animation_player_up(t_window *window);
void    initialize_structures(t_textures *textures, t_window *window);
void	load_textures_enemy(t_window *window, t_textures *textures);
int	animation_player_enemys(t_window *window);

#endif
