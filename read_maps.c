/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:13:35 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/15 13:58:31 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long.h"

void	read_map_ul(char **line, int fd_file)
{
	*line = get_next_line(fd_file);
	if (!*line)
	{
		close(fd_file);
		print_message("\033[0;91mError\nempty map file\033[0;39m", 2);
	}
}

char	**read_map(char *filename)
{
	int		fd_file;
	char	**res_map;
	int		i;
	char	*line;

	i = 0;
	fd_file = open(filename, O_RDONLY);
	if (fd_file == -1)
		print_message("\033[0;91mError\nopening file\033[0;39m", 2);
	res_map = malloc(sizeof(char *) * 100);
	if (!res_map)
	{
		close(fd_file);
		print_message("\033[0;91mError\nallocating memory\033[0;39m", 2);
	}
	read_map_ul(&line, fd_file);
	while (line)
	{
		res_map[i] = line;
		i++;
		line = get_next_line(fd_file);
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
		mlx_put_image_to_window(window->mlx, window->mlx_win, textures.coin,
			indexx->j * TILE_SIZE, indexx->i * TILE_SIZE);
	else if (window->map[indexx->i][indexx->j] == 'P'
			|| window->map[indexx->i][indexx->j] == 'E')
		mlx_put_image_to_window(window->mlx, window->mlx_win, textures.floor,
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
