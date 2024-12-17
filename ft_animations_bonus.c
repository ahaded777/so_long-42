/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:02:41 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/17 19:02:45 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long_bonus.h"

int	d(void)
{
	static int	time = 0;

	if (time < 5900)
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

	i = 0;
	if (d() == 0)
		return (0);
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
	return (0);
}
