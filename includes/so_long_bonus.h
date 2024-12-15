/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:06:03 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/15 14:06:07 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 64
# define ESC_KEY 65307
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363

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
	void			*ex_op;
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
	t_player_move	*player;
	t_textures		textures;
	t_map_size		*map_size;
}					t_window;

void				free_map(char **map);
void				print_message(char *message, int fd);
void				ft_check_map(char *filename);
char				**read_map(char *filename);
int					ft_check_wall_up(char **map);
int					close_window(void *par);
int					ft_check_wall_down(char **map);
int					ft_check_wall_up_and_down(int len_wall_up,
						int len_wall_down);
int					handle_keypress(int keycode, t_window *window);
int					ft_check_wall_right_and_left(int len_wall, char **map);
void				size_map(t_window *window, t_map_size *map_size);
void				check_player_map(t_window window, t_player_move *player);
void				render_map(t_textures textures, t_window *window,
						t_player_move player);
void				ft_check_elements(char *filename);

#endif
