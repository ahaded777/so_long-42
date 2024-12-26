/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <aahaded@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:30:03 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/19 10:26:58 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long_bonus.h"

void	eat_coins(t_window *window)
{
	if (window->map[window->player->y][window->player->x] == 'C')
	{
		window->map[window->player->y][window->player->x] = '0';
		window->player->coins += 1;
	}
}

void	draw_player(t_window *window, int x, int y, int keycode)
{
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->textures.player, x * TILE_SIZE, y * TILE_SIZE);
	if ((keycode == 'W' || keycode == 'w' || keycode == UP_KEY)
		&& window->map[window->player->y - 1][window->player->x] != '1')
		animation_player_up(window);
	if ((keycode == 'S' || keycode == 's' || keycode == DOWN_KEY)
		&& window->map[window->player->y + 1][window->player->x] != '1')
		animation_player_down(window);
	if ((keycode == 'A' || keycode == 'a' || keycode == LEFT_KEY)
		&& window->map[window->player->y][window->player->x - 1] != '1')
		animation_player_left(window);
	if ((keycode == 'D' || keycode == 'd' || keycode == RIGHT_KEY)
		&& window->map[window->player->y][window->player->x + 1] != '1')
		animation_player_right(window);
	if (window->map[y][x] == 'E'
		&& window->count_coins == window->player->coins)
		print_message("\033[0;92m-------> YOU WIN\n\033[0;39m", 1);
}

void	erase_tile(t_window *window, int x_old, int y_old)
{
	eat_coins(window);
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->textures.floor, x_old * TILE_SIZE, y_old * TILE_SIZE);
	if (window->count_coins == window->player->coins)
		mlx_put_image_to_window(window->mlx, window->mlx_win,
			window->textures.exit, window->x_door * TILE_SIZE, window->y_door
			* TILE_SIZE);
	else
		mlx_put_image_to_window(window->mlx, window->mlx_win,
			window->textures.floor, window->x_door * TILE_SIZE, window->y_door
			* TILE_SIZE);
}

void	handle_keypress_ul(t_window *window, int keycode)
{
	if ((keycode == 'D' || keycode == 'd' || keycode == RIGHT_KEY)
		&& window->map[window->player->y][window->player->x + 1] != '1')
	{
		window->player->x += 1;
		window->move_count++;
	}
	else if ((keycode == 'A' || keycode == 'a' || keycode == LEFT_KEY)
		&& window->map[window->player->y][window->player->x - 1] != '1')
	{
		window->player->x -= 1;
		window->move_count++;
	}
	else if ((keycode == 'W' || keycode == 'w' || keycode == UP_KEY)
		&& window->map[window->player->y - 1][window->player->x] != '1')
	{
		window->player->y -= 1;
		window->move_count++;
	}
	else if ((keycode == 'S' || keycode == 's' || keycode == DOWN_KEY)
		&& window->map[window->player->y + 1][window->player->x] != '1')
	{
		window->player->y += 1;
		window->move_count++;
	}
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
	handle_keypress_ul(window, keycode);
	erase_tile(window, old_x, old_y);
	draw_player(window, window->player->x, window->player->y, keycode);
	mlx_put_image_to_window(window->mlx, window->mlx_win, window->textures.wall,
		0 * TILE_SIZE, 0 * TILE_SIZE);
	clear_text_area(window);
	window->str = ft_itoa(window->move_count);
	mlx_string_put(window->mlx, window->mlx_win, 10, 30, 0xFFFFFF, "Moves: ");
	mlx_string_put(window->mlx, window->mlx_win, 55, 30, 0XFFFFFF, window->str);
	free(window->str);
	return (0);
}
