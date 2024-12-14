/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:37:30 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/14 13:35:38 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/so_long.h"

void	find_player_position(char **map, t_player_move *player)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player->x = j;
				player->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	print_message("Error: Player not found on the map\n", 2);
}

int	total_coins_count(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	flood_fill(char **map, int x, int y, int *coins)
{
	int	exit_found;

	exit_found = 0;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'C')
		(*coins)++;
	if (map[y][x] == 'E')
		exit_found = 1;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, coins);
	flood_fill(map, x - 1, y, coins);
	flood_fill(map, x, y + 1, coins);
	flood_fill(map, x, y - 1, coins);
	return (exit_found);
}

void	check_map(char **map, int player_x, int player_y)
{
	int	coins;
	int	exit_found;
	int	total_coins;

	coins = 0;
	exit_found = 0;
	total_coins = total_coins_count(map);
	exit_found = flood_fill(map, player_x, player_y, &coins);
	if (coins < total_coins)
		print_message("Error: All coins are not accessible\n", 2);
	if (!exit_found)
		print_message("Error: Exit is not reachable\n", 2);
}

void	ft_check_map(char *filename)
{
	t_player_move	player;
	char			**map;
	int				len_wall_up;
	int				len_wall_down;

	map = read_map(filename);
	if (!map)
		print_message("Error: Failed to read map\n", 2);
	len_wall_up = ft_check_wall_up(map);
	len_wall_down = ft_check_wall_down(map);
	ft_check_wall_up_and_down(len_wall_up, len_wall_down);
	ft_check_wall_right_and_left(len_wall_up, map);
	find_player_position(map, &player);
	check_map(map, player.x, player.y);
	free_map(map);
}
