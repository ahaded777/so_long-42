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
	window->textures.count_pl_frames = (window->textures.count_pl_frames += 1)
		% COUNT_IMAGE_PLAYER_LEFT;
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->textures.p_left_frames[window->textures.count_pl_frames],
		window->player->x * TILE_SIZE, window->player->y * TILE_SIZE);
	return (0);
}

int	animation_player_right(t_window *window)
{
	window->textures.count_pr_frames = (window->textures.count_pr_frames += 1)
		% COUNT_IMAGE_PLAYER_R;
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->textures.p_r_frames[window->textures.count_pr_frames],
		window->player->x * TILE_SIZE, window->player->y * TILE_SIZE);
	return (0);
}

int	animation_player_up(t_window *window)
{
	window->textures.count_pu_frames = (window->textures.count_pu_frames += 1)
		% COUNT_IMAGE_PLAYER_UP;
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->textures.p_up_frames[window->textures.count_pu_frames],
		window->player->x * TILE_SIZE, window->player->y * TILE_SIZE);
	return (0);
}

int	animation_player_enemys(t_window *window)
{
	int	i;
	int	j;

	i = 0;
	window->textures.c_en_frames = (window->textures.c_en_frames += 1)
		% COUNT_IMAGE_ENEMY;
	while (window->map[i])
	{
		j = 0;
		while (window->map[i][j])
		{
			if (window->map[i][j] == 'F')
			{
				mlx_put_image_to_window(window->mlx, window->mlx_win,
					window->textures.p_en_frames[window->textures.c_en_frames],
					j * TILE_SIZE, i * TILE_SIZE);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	all_animation(t_window *window)
{
	animation_coins(window);
	window->textures.p_timer++;
	if (window->textures.p_timer == 50000)
	{
		animation_player_right(window);
		animation_player_left(window);
		animation_player_down(window);
		animation_player_up(window);
		animation_player(window);
		window->textures.p_timer = 0;
	}
	return (0);
}
