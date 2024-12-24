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

void	load_textures_enemy(t_window *window, t_textures *textures)
{
	textures->p_en_frames[0] = mlx_xpm_file_to_image(window->mlx,
			"./textures/ene_/en_0.xpm", &window->img_width,
			&window->img_height);
	textures->p_en_frames[1] = mlx_xpm_file_to_image(window->mlx,
			"./textures/ene_/en_1.xpm", &window->img_width,
			&window->img_height);
	textures->p_en_frames[2] = mlx_xpm_file_to_image(window->mlx,
			"./textures/ene_/en_2.xpm", &window->img_width,
			&window->img_height);
	textures->p_en_frames[3] = mlx_xpm_file_to_image(window->mlx,
			"./textures/ene_/en_3.xpm", &window->img_width,
			&window->img_height);
	if (!textures->p_en_frames[0] || !textures->p_en_frames[1]
		|| !textures->p_en_frames[2] || !textures->p_en_frames[3])
		print_message("Error\nFailed to load textures\n", 2);
}

void	load_textures_player(t_window *window, t_textures *textures)
{
	textures->player_frames[0] = mlx_xpm_file_to_image(window->mlx,
			"./textures/I_r/p_1.xpm", &window->img_width,
			&window->img_height);
	textures->player_frames[1] = mlx_xpm_file_to_image(window->mlx,
			"./textures/I_r/p_2.xpm", &window->img_width,
			&window->img_height);
	textures->p_up_frames[0] = mlx_xpm_file_to_image(window->mlx,
			"./textures/p_up/pu_1.xpm", &window->img_width,
			&window->img_height);
	textures->p_up_frames[1] = mlx_xpm_file_to_image(window->mlx,
			"./textures/p_up/pu_3.xpm", &window->img_width,
			&window->img_height);
	textures->p_r_frames[0] = mlx_xpm_file_to_image(window->mlx,
			"./textures/p_r/pr.xpm", &window->img_width,
			&window->img_height);
	textures->p_left_frames[0] = mlx_xpm_file_to_image(window->mlx,
			"./textures/p_l/pl.xpm", &window->img_width,
			&window->img_height);
	if (!textures->player_frames[0] || !textures->player_frames[1]
		|| !textures->p_up_frames[0] || !textures->p_up_frames[1]
		|| !textures->p_r_frames[0] || !textures->p_left_frames[0])
		print_message("Error\nFailed to load textures\n", 2);
}

void	load_textures_coins(t_window *window, t_textures *textures)
{
	textures->coin_frames[0] = mlx_xpm_file_to_image(window->mlx,
			"./textures/cs/c_1.xpm", &window->img_width,
			&window->img_height);
	textures->coin_frames[1] = mlx_xpm_file_to_image(window->mlx,
			"./textures/cs/c_2.xpm", &window->img_width,
			&window->img_height);
	textures->coin_frames[2] = mlx_xpm_file_to_image(window->mlx,
			"./textures/cs/c_3.xpm", &window->img_width,
			&window->img_height);
	textures->coin_frames[3] = mlx_xpm_file_to_image(window->mlx,
			"./textures/cs/c_4.xpm", &window->img_width,
			&window->img_height);
	textures->coin_frames[4] = mlx_xpm_file_to_image(window->mlx,
			"./textures/cs/c_5.xpm", &window->img_width,
			&window->img_height);
	textures->coin_frames[5] = mlx_xpm_file_to_image(window->mlx,
			"./textures/cs/c_6.xpm", &window->img_width,
			&window->img_height);
	load_textures_player(window, textures);
	if (!textures->coin_frames[0] || !textures->coin_frames[1]
		|| !textures->coin_frames[2] || !textures->coin_frames[3]
		|| !textures->coin_frames[4] || !textures->coin_frames[5])
		print_message("Error\nFailed to load textures\n", 2);
}
