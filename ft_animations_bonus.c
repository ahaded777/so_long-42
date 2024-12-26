/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animations_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:02:41 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/19 10:30:18 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long_bonus.h"

int	animation_player_left(t_window *window)
{
	window->textures.count_pl_frames = (window->textures.count_pl_frames + 1)
		% COUNT_IMAGE_PLAYER_LEFT;
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->textures.p_left_frames[window->textures.count_pl_frames],
		window->player->x * TILE_SIZE, window->player->y * TILE_SIZE);
	return (0);
}

int	animation_player_right(t_window *window)
{
	window->textures.count_pr_frames = (window->textures.count_pr_frames + 1)
		% COUNT_IMAGE_PLAYER_R;
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->textures.p_r_frames[window->textures.count_pr_frames],
		window->player->x * TILE_SIZE, window->player->y * TILE_SIZE);
	return (0);
}

int	animation_player_up(t_window *window)
{
	window->textures.count_pu_frames = (window->textures.count_pu_frames + 1)
		% COUNT_IMAGE_PLAYER_UP;
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->textures.p_up_frames[window->textures.count_pu_frames],
		window->player->x * TILE_SIZE, window->player->y * TILE_SIZE);
	return (0);
}

int	animation_player_enemys(t_window *window)
{
	static int	delay_timer = 0;

	if (delay_timer < 120)
	{
		delay_timer++;
		return (0);
	}
	window->textures.timer_enemys++;
	if (window->textures.timer_enemys >= 35000)
	{
		animation_player_enemys_ul(window);
		window->textures.timer_enemys = 0;
		delay_timer = 0;
	}
	return (0);
}

int	all_animation(t_window *window)
{
	animation_coins(window);
	window->textures.timer_player++;
	if (window->textures.timer_player >= 45000)
	{
		animation_player_right(window);
		animation_player_left(window);
		animation_player_up(window);
		animation_player(window);
		window->textures.timer_player = 0;
	}
	animation_player_enemys(window);
	if (window->map[window->player->y][window->player->x] == 'F')
		mlx_put_image_to_window(window->mlx, window->mlx_win,
			window->textures.player, window->player->x * TILE_SIZE,
			window->player->y * TILE_SIZE);
	if (window->map[window->player->y][window->player->x] == 'F'
		&& window->textures.c_en_frames != 0)
		print_message("Game Over: You stepped into danger!\n", 1);
	return (0);
}
