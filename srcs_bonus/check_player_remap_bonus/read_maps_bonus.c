/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <aahaded@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:12:47 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/15 22:12:49 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/so_long_bonus.h"

char	**read_map(char *filename)
{
	int		fd_file;
	char	**res_map;
	int		i;
	char	*line;

	i = 0;
	fd_file = open(filename, O_RDONLY);
	if (fd_file == -1)
		print_message("Error: opening file", 2);
	res_map = malloc(sizeof(char *) * 100);
	if (!res_map)
		print_message("Error: allocating memory", 2);
	while (1)
	{
		line = get_next_line(fd_file);
		if (!line)
			break ;
		res_map[i] = line;
		i++;
	}
	res_map[i] = NULL;
	close(fd_file);
	return (res_map);
}

void	render_tile(t_window *window, t_textures textures,
		t_render_index *indexx, t_player_move player)
{
	if (window->map[indexx->i][indexx->j] == '1')
		mlx_put_image_to_window(window->mlx, window->mlx_win, textures.wall,
			indexx->j * TILE_SIZE, indexx->i * TILE_SIZE);
	else if (window->map[indexx->i][indexx->j] == '0')
		mlx_put_image_to_window(window->mlx, window->mlx_win, textures.floor,
			indexx->j * TILE_SIZE, indexx->i * TILE_SIZE);
	else if (window->map[indexx->i][indexx->j] == 'C')
	{
		mlx_put_image_to_window(window->mlx, window->mlx_win, textures.coin,
			indexx->j * TILE_SIZE, indexx->i * TILE_SIZE);
	}
		// mlx_put_image_to_window(window->mlx, window->mlx_win, textures.coin,
		// 	indexx->j * TILE_SIZE, indexx->i * TILE_SIZE);
	else if (window->map[indexx->i][indexx->j] == 'P')
		mlx_put_image_to_window(window->mlx, window->mlx_win, textures.floor,
			indexx->j * TILE_SIZE, indexx->i * TILE_SIZE);
	else if (window->map[indexx->i][indexx->j] == 'E')
		mlx_put_image_to_window(window->mlx, window->mlx_win, textures.ex_op,
			indexx->j * TILE_SIZE, indexx->i * TILE_SIZE);
	if (indexx->i == player.y && indexx->j == player.x)
		mlx_put_image_to_window(window->mlx, window->mlx_win, textures.player,
			indexx->j * TILE_SIZE, indexx->i * TILE_SIZE);
}

void	render_map(t_textures textures, t_window *window, t_player_move player)
{
	t_render_index	index;

	index.i = 0;
	while (window->map[index.i])
	{
		index.j = 0;
		while (window->map[index.i][index.j])
		{
			render_tile(window, textures, &index, player);
			index.j++;
		}
		index.i++;
	}
}

void	size_map(t_window *window, t_map_size *map_size)
{
	int	x;
	int	y;

	y = 0;
	window->count_coins = 0;
	while (window->map[y])
	{
		x = 0;
		while (window->map[y][x])
		{
			if (window->map[y][x] == 'C')
				window->count_coins += 1;
			x++;
		}
		y++;
	}
	x = 0;
	y = 0;
	while (window->map[y])
		y++;
	map_size->len_y += y;
	while (window->map[0][x] != '\n')
		x++;
	map_size->len_x += x;
}
