/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:06:54 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/15 14:06:57 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void	print_message(char *message, int fd)
{
	ft_putstr_fd(message, fd);
	if (fd == 2)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}

void	load_textures(t_window *window, t_textures *textures)
{
	textures->wall = mlx_xpm_file_to_image(window->mlx, "./textures/wall.xpm",
			&window->img_width, &window->img_height);
	textures->floor = mlx_xpm_file_to_image(window->mlx, "./textures/floor.xpm",
			&window->img_width, &window->img_height);
	textures->player = mlx_xpm_file_to_image(window->mlx, "./textures/p1.xpm",
			&window->img_width, &window->img_height);
	textures->coin = mlx_xpm_file_to_image(window->mlx, "./textures/coin.xpm",
			&window->img_width, &window->img_height);
	textures->exit = mlx_xpm_file_to_image(window->mlx, "./textures/exit.xpm",
			&window->img_width, &window->img_height);
	textures->ex_op = mlx_xpm_file_to_image(window->mlx, "./textures/ex_op.xpm",
			&window->img_width, &window->img_height);
	if (!textures->wall || !textures->floor || !textures->player
		|| !textures->coin || !textures->exit)
		print_message("Error: Failed to load textures\n", 2);
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
	ft_check_elements(filename);
	window->mlx = mlx_init();
	if (!window->mlx)
		print_message("Error: Failed (X server problem)\n", 2);
	window->map = read_map(filename);
	if (!window->map)
		print_message("Error: Failed to read map\n", 2);
}

int	main(int ac, char **av)
{
	t_window		window;
	t_textures		textures;
	t_map_size		map_size;
	t_player_move	player;

	if (ac != 2)
		print_message("Usage: ./so_long <map_file>\n", 2);
	ft_check_map(av[1]);
	init_environment(&window, av[1]);
	init_map_data(&window, &map_size, &player);
	window.mlx_win = mlx_new_window(window.mlx, map_size.len_x * TILE_SIZE,
			map_size.len_y * TILE_SIZE, "GTA SAN");
	if (!window.mlx_win)
		print_message("Error: Failed to create window\n", 2);
	load_textures(&window, &textures);
	window.textures = textures;
	render_map(textures, &window, player);
	mlx_hook(window.mlx_win, 17, 0, close_window, NULL);
	mlx_hook(window.mlx_win, KeyPress, KeyPressMask, handle_keypress, &window);
	mlx_loop(window.mlx);
	exit(EXIT_SUCCESS);
}
