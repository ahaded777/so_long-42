/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:13:26 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/14 14:13:28 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/so_long.h"

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

void	eat_coins(t_window *window)
{
	if (window->map[window->player->y][window->player->x] == 'C')
	{
		window->map[window->player->y][window->player->x] = '0';
		window->player->coins += 1;
	}
}

int	handle_keypress(int keycode, t_window *window)
{
	t_player_move	*player;

	player = window->player;
	if (keycode == ESC_KEY)
		exit(EXIT_SUCCESS);
	if ((keycode == 'D' || keycode == 'd' || keycode == RIGHT_KEY)
		&& window->map[window->player->y][window->player->x + 1] != '1')
		window->player->x += 1;
	else if ((keycode == 'A' || keycode == 'a' || keycode == LEFT_KEY)
		&& window->map[window->player->y][window->player->x - 1] != '1')
		window->player->x -= 1;
	else if ((keycode == 'W' || keycode == 'w' || keycode == UP_KEY)
		&& window->map[window->player->y - 1][window->player->x] != '1')
		window->player->y -= 1;
	else if ((keycode == 'S' || keycode == 's' || keycode == DOWN_KEY)
		&& window->map[window->player->y + 1][window->player->x] != '1')
		window->player->y += 1;
	mlx_clear_window(window->mlx, window->mlx_win);
	eat_coins(window);
	render_map(window->textures, window, *player);
	return (0);
}
