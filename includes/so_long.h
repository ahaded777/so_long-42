/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:14:47 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/13 11:25:45 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define TILE_SIZE 64

# define ESC_KEY 65307
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363


typedef struct s_player_move_and_data {
    int x;  
    int y;
    int coins;
}   t_player_move_and_data;

typedef struct s_textures {
    void    *wall;     
    void    *floor;   
    void    *player;  
    void    *coin;  
    void    *exit;  
}   t_textures;

typedef struct s_map_size {
    int len_x;
    int len_y;
    int count_coins_map;
}   t_map_size;

typedef struct s_window {
    void            *mlx;
    void            *mlx_win;
    char            **map;
    int             img_width; 
    int             img_height;
    int			cox;
    t_player_move_and_data   *player; 
    t_textures      textures;
    t_map_size	*map_size;
}   t_window;



#endif
