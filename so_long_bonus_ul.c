/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_ul.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:51:51 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/17 19:51:55 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long_bonus.h"

void	ft_mlx_loop_hook(t_window *window)
{
	mlx_loop_hook(window->mlx, animation_coins, window);
	//mlx_loop_hook(window.mlx, animation_player, &window);
}

void	load_textures_player(t_window *window, t_textures *textures)
{
	textures->player_frames[0] = mlx_xpm_file_to_image(window->mlx,
			"./textures/I_r/p_1.xpm", &window->img_width,
			&window->img_height);
	textures->player_frames[1] = mlx_xpm_file_to_image(window->mlx,
			"./textures/I_r/p_2.xpm", &window->img_width,
			&window->img_height);
	if (!textures->player_frames[0]
        || !textures->player_frames[1])
		print_message("Error\nFailed to load textures\n", 2);
}