/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:41:44 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/20 12:41:45 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long.h"

void	initialize_structures_window(t_window *window)
{
	window->mlx = NULL;
	window->mlx_win = NULL;
	window->map = NULL;
	window->img_width = 0;
	window->img_height = 0;
	window->count_coins = 0;
	window->x = 0;
	window->y = 0;
	window->index_door.i = 0;
	window->index_door.j = 0;
	window->move_count = 0;
}

void	initialize_structures_textures(t_textures *textures)
{
	textures->wall = NULL;
	textures->floor = NULL;
	textures->player = NULL;
	textures->coin = NULL;
	textures->exit = NULL;
}

void	initialize_structures(t_textures *textures, t_window *window)
{
	initialize_structures_textures(textures);
	initialize_structures_window(window);
}
