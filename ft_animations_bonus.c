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

int	ft_sleep_coins(int num)
{
	static int	time = 0;
	if (time <= num)
	{
		time++;
		return (0);
	}
	time = 0;
	return (1);
}

int	animation_coins(t_window *window)
{
	int	i;
	int	j;

	window->textures.coin_timer++;
	if (window->textures.coin_timer == 5200)
	{
		i = 0;
		window->textures.count_frames = (window->textures.count_frames += 1)
			% COUNT_IMAGE_ANIM;
		while (window->map[i])
		{
			j = 0;
			while (window->map[i][j])
			{
				if (window->map[i][j] == 'C')
				{
					mlx_put_image_to_window(window->mlx, window->mlx_win,
						window->textures.coin_frames[window->textures.count_frames],
						j * TILE_SIZE, i * TILE_SIZE);
				}
				j++;
			}
			i++;
		}
		window->textures.coin_timer = 0;
	}
	return (0);
}

int	animation_player(t_window *window)
{
	// window->textures.p_timer++;
	// if (window->textures.p_timer == 10500)
	// {
	// 	window->textures.p_timer = 0;
	// }
	window->textures.count_p_frames = (window->textures.count_p_frames += 1)
		% COUNT_IMAGE_PLAYER;
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->textures.player_frames[window->textures.count_p_frames],
		window->player->x * TILE_SIZE, window->player->y * TILE_SIZE);
	return (0);
}

int	animation_player_down(t_window *window)
{
	window->textures.count_pd_frames = (window->textures.count_pd_frames += 1)
		% COUNT_IMAGE_PLAYER_DOWN;
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->textures.p_down_frames[window->textures.count_pd_frames],
		window->player->x * TILE_SIZE, window->player->y * TILE_SIZE);
	return (0);
}

// int	animation_player_left(t_window *window)
// {
// 	window->textures.count_pl_frames = (window->textures.count_pl_frames += 1)
// 		% COUNT_IMAGE_PLAYER_DOWN;
// 	mlx_put_image_to_window(window->mlx, window->mlx_win,
// 		window->textures.p_left_frames[window->textures.count_pl_frames],
// 		window->player->x * TILE_SIZE, window->player->y * TILE_SIZE);
// 	return (0);
// }

int	animation_player_up(t_window *window)
{
	// window->textures.p_timer++;
	// if (window->textures.p_timer == 9000)
	// {
	// }
	window->textures.count_pu_frames = (window->textures.count_pu_frames += 1)
		% COUNT_IMAGE_PLAYER_UP;
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->textures.p_up_frames[window->textures.count_pu_frames],
		window->player->x * TILE_SIZE, window->player->y * TILE_SIZE);
	return (0);
}

int	all_animation(t_window *window)
{
	animation_coins(window);
	window->textures.p_timer++;
	if (window->textures.p_timer == 45000)
	{
		animation_player_down(window);
		animation_player_up(window);
		animation_player(window);
		window->textures.p_timer = 0;
	}
	return (0);
}