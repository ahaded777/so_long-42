/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <aahaded@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:30:42 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/17 16:30:44 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long_bonus.h"

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
	if (!textures->coin_frames[0] || !textures->coin_frames[1]
		|| !textures->coin_frames[2] || !textures->coin_frames[3]
		|| !textures->coin_frames[4] || !textures->coin_frames[5])
		print_message("Error\nFailed to load textures\n", 2);
}

void	load_textures(t_window *window, t_textures *textures)
{
	textures->wall = mlx_xpm_file_to_image(window->mlx,
			"./textures/wall.xpm", &window->img_width,
			&window->img_height);
	textures->floor = mlx_xpm_file_to_image(window->mlx, "./textures/floor.xpm",
			&window->img_width, &window->img_height);
	textures->player = mlx_xpm_file_to_image(window->mlx, "./textures/p1.xpm",
			&window->img_width, &window->img_height);
	textures->coin = mlx_xpm_file_to_image(window->mlx, "./textures/cs/c_1.xpm",
			&window->img_width, &window->img_height);
	textures->exit = mlx_xpm_file_to_image(window->mlx, "./textures/exit.xpm",
			&window->img_width, &window->img_height);
	// player
	textures->player_frames[0] = mlx_xpm_file_to_image(window->mlx,
			"./textures/I_r/p_1.xpm", &window->img_width,
			&window->img_height);
	textures->player_frames[1] = mlx_xpm_file_to_image(window->mlx,
			"./textures/I_r/p_2.xpm", &window->img_width,
			&window->img_height); 
	/////////
	// player up
	textures->p_up_frames[0] = mlx_xpm_file_to_image(window->mlx,
			"./textures/p_up/pu_1.xpm", &window->img_width,
			&window->img_height);
	textures->p_up_frames[1] = mlx_xpm_file_to_image(window->mlx,
			"./textures/p_up/pu_3.xpm", &window->img_width,
			&window->img_height); 
	/////////
	// player down
	textures->p_down_frames[0] = mlx_xpm_file_to_image(window->mlx,
			"./textures/p_d/pd_1.xpm", &window->img_width,
			&window->img_height);
	textures->p_down_frames[1] = mlx_xpm_file_to_image(window->mlx,
			"./textures/p_d/pd_3.xpm", &window->img_width,
			&window->img_height); 
	/////////
	//load_textures_player(window, textures);
	load_textures_coins(window, textures);
	if (!textures->wall || !textures->floor || !textures->player
		|| !textures->coin || !textures->exit)
		print_message("Error\nFailed to load textures\n", 2);
}

void	init_map_data(t_window *window, t_map_size *map_size,
		t_player_move *player)
{
	size_map(window, map_size);
	check_player_map(*window, player);
	window->player = player;
}

void	init_environment(t_window *window, char *filename)
{
	window->mlx = mlx_init();
	if (!window->mlx)
		print_message("Error\nFailed (X server problem)\n", 2);
	window->map = read_map(filename);
	if (!window->map)
		print_message("Error\nFailed to read map\n", 2);
}

void initialize_structures(t_textures *textures)
{
    textures->count_frames = 0;
    textures->count_p_frames = 0;
    textures->count_pd_frames = 0;
    //textures->count_pl_frames = 0;
    textures->count_pu_frames = 0;
    textures->coin_timer = 0;
    textures->p_timer = 0;
    textures->wall = NULL;
    textures->floor = NULL;
    textures->player = NULL;
    textures->coin = NULL;
    textures->exit = NULL;
	int i;
	
	i = 0;
    while (i < COUNT_IMAGE_ANIM)
	{
        textures->coin_frames[i] = NULL;
		i++;
	}
	i = 0;
    while (i < COUNT_IMAGE_PLAYER)
	{
        textures->player_frames[i] = NULL;
		i++;
	}
	i = 0;
    while (i < COUNT_IMAGE_PLAYER_UP)
    {
        textures->p_down_frames[i] = NULL;
        textures->p_up_frames[i] = NULL;
		i++;
    }
}


int	main(int ac, char **av)
{
	t_window		window;
	t_textures		textures;
	t_map_size		map_size;
	t_player_move	player;

	if (ac != 2)
		print_message("Usage: ./so_long <map_file>\n", 2);
	initialize_structures(&textures);
	ft_check_filename(av[1]);
	ft_check_map(av[1]);
	init_environment(&window, av[1]);
	init_map_data(&window, &map_size, &player);
	window.mlx_win = mlx_new_window(window.mlx, map_size.len_x * TILE_SIZE,
			map_size.len_y * TILE_SIZE, "GAME");
	if (!window.mlx_win)
		print_message("Error\nFailed to create window\n", 2);
	load_textures(&window, &textures);
	window.textures = textures;
	render_map(textures, &window, player);
	mlx_hook(window.mlx_win, 17, 0, close_window, NULL);
	mlx_hook(window.mlx_win, KeyRelease, KeyReleaseMask, handle_keypress, &window);
	window.textures.coin_timer = 0;
	window.textures.p_timer = 0;
	mlx_loop_hook(window.mlx, all_animation, &window);
	mlx_loop(window.mlx);
	exit(EXIT_SUCCESS);
}
