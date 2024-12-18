/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:13:26 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/18 09:32:20 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long.h"

void	eat_coins(t_window *window)
{
	if (window->map[window->player->y][window->player->x] == 'C')
	{
		window->map[window->player->y][window->player->x] = '0';
		window->player->coins += 1;
	}
}

void	draw_player(t_window *window, int x, int y)
{
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->textures.player, x * TILE_SIZE, y * TILE_SIZE);
	if (window->map[y][x] == 'E'
		&& window->count_coins == window->player->coins)
		print_message("\033[0;92m-------> YOU WIN\n\033[0;39m", 2);
}

void	erase_tile(t_window *window, int x, int y)
{
	eat_coins(window);
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->textures.floor, x * TILE_SIZE, y * TILE_SIZE);
	if (window->count_coins == window->player->coins)
		mlx_put_image_to_window(window->mlx, window->mlx_win,
			window->textures.exit, window->x * TILE_SIZE, window->y
			* TILE_SIZE);
	else
		mlx_put_image_to_window(window->mlx, window->mlx_win,
			window->textures.floor, window->x * TILE_SIZE, window->y
			* TILE_SIZE);
}

int	handle_keypress(int keycode, t_window *window)
{
	int	old_x;
	int	old_y;

	old_x = window->player->x;
	old_y = window->player->y;
	check_door_map(window);
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
	erase_tile(window, old_x, old_y);
	draw_player(window, window->player->x, window->player->y);
	return (0);
}
