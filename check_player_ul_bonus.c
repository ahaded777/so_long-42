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
#include "./so_long.h"

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
