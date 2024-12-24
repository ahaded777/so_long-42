/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animations_ul_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:54:47 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/20 21:54:48 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long_bonus.h"

void	animation_coins_ul(t_window *window)
{
	int	i;
	int	j;

	i = 0;
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
}

int	animation_coins(t_window *window)
{
	window->textures.coin_timer++;
	if (window->textures.coin_timer >= 5800)
	{
		window->textures.count_frames = (window->textures.count_frames + 1)
			% COUNT_IMAGE_ANIM;
		animation_coins_ul(window);
		window->textures.coin_timer = 0;
	}
	return (0);
}

int	animation_player(t_window *window)
{
	window->textures.count_p_frames = (window->textures.count_p_frames + 1)
		% COUNT_IMAGE_PLAYER;
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->textures.player_frames[window->textures.count_p_frames],
		window->player->x * TILE_SIZE, window->player->y * TILE_SIZE);
	return (0);
}

int	animation_player_down(t_window *window)
{
	window->textures.count_pd_frames = (window->textures.count_pd_frames + 1)
		% COUNT_IMAGE_PLAYER_DOWN;
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->textures.p_down_frames[window->textures.count_pd_frames],
		window->player->x * TILE_SIZE, window->player->y * TILE_SIZE);
	return (0);
}
