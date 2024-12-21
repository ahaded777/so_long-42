/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_ul_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <aahaded@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:30:09 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/17 16:30:13 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long_bonus.h"

void	clear_text_area(t_window *window)
{
	int	i;
	int	j;

	i = 10;
	while (i < 125)
	{
		j = 20;
		while (j < 40)
		{
			mlx_pixel_put(window->mlx, window->mlx_win, i, j, 0x000000);
			j++;
		}
		i++;
	}
}

void	check_door_map(t_window *window)
{
	int	x;
	int	y;

	y = 0;
	while (window->map[y])
	{
		x = 0;
		while (window->map[y][x])
		{
			if (window->map[y][x] == 'E')
			{
				window->x = x;
				window->y = y;
			}
			x++;
		}
		y++;
	}
}

void	check_player_map(t_window window, t_player_move *player)
{
	int	x;
	int	y;

	y = 0;
	while (window.map[y])
	{
		x = 0;
		while (window.map[y][x])
		{
			if (window.map[y][x] == 'P')
			{
				player->x = x;
				player->y = y;
			}
			x++;
		}
		y++;
	}
}
