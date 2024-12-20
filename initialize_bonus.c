/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:31:03 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/20 12:31:04 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long_bonus.h"

void    initialize_structures_window(t_window *window)
{
    window->img_width = 0;
	window->img_height = 0;
	window->count_coins = 0;
	window->x = 0;
	window->y = 0;
    window->map = NULL;
    window->mlx = NULL;
	window->mlx_win = NULL;
    window->index_door.i = 0;
	window->index_door.j = 0;
    window->move_count = 0;
}

void    initialize_structures_textures_en(t_textures *textures)
{
    int j;
	
	j = 0;
    while (j < COUNT_IMAGE_ENEMY)
	{
        textures->p_en_frames[j] = NULL;
		j++;
	}
    
}

void    initialize_structures_textures_ul(t_textures *textures)
{
    int i;
	
	i = 0;
    while (i < COUNT_IMAGE_ANIM)
	{
        textures->coin_frames[i] = NULL;
		i++;
	}
	i = 0;
    while (i < COUNT_IMAGE_PLAYER)
	{
        textures->player_frames[i] = NULL;
		i++;
	}
	i = 0;
    while (i < COUNT_IMAGE_PLAYER_UP)
    {
        textures->p_down_frames[i] = NULL;
        textures->p_up_frames[i] = NULL;
		i++;
    }
    initialize_structures_textures_en(textures);
}

void initialize_structures_textures(t_textures *textures)
{
    textures->count_frames = 0;
    textures->count_p_frames = 0;
    textures->count_pd_frames = 0;
    textures->count_pl_frames = 0;
    textures->count_pu_frames = 0;
    textures->coin_timer = 0;
    textures->p_timer = 0;
    textures->wall = NULL;
    textures->floor = NULL;
    textures->player = NULL;
    textures->coin = NULL;
    textures->exit = NULL;
	initialize_structures_textures_ul(textures);
}

void    initialize_structures(t_textures *textures, t_window *window)
{
    initialize_structures_textures(textures);
    initialize_structures_window(window);
}