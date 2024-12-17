/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:29:23 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/17 16:29:26 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long_bonus.h"

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
	free_map(map);
	print_message("Error\nPlayer not found on the map\n",
		2);
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

int	flood_fill(char **map, int x, int y, t_exit_coins *exicoin)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'C')
		exicoin->coins_++;
	if (map[y][x] == 'E')
		exicoin->num_exit = 1;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, exicoin);
	flood_fill(map, x - 1, y, exicoin);
	flood_fill(map, x, y + 1, exicoin);
	flood_fill(map, x, y - 1, exicoin);
	return (0);
}

void	check_map(char **map, int player_x, int player_y)
{
	t_exit_coins	exicoin;
	int				total_coins;

	exicoin.num_exit = 0;
	exicoin.coins_ = 0;
	total_coins = total_coins_count(map);
	flood_fill(map, player_x, player_y, &exicoin);
	if (exicoin.coins_ < total_coins)
	{
		free_map(map);
		print_message("Error\nAll coins are not accessible\n", 2);
	}
	if (!exicoin.num_exit)
	{
		free_map(map);
		print_message("Error\nExit is not reachable\n", 2);
	}
}

void	ft_check_map(char *filename)
{
	t_player_move	player;
	char			**map;

	map = read_map(filename);
	if (!map)
		print_message("Error\nFailed to read map\n", 2);
	ft_check_map_v1(map);
	ft_check_map_walls(map);
	ft_check_elements(map);
	find_player_position(map, &player);
	check_map(map, player.x, player.y);
	free_map(map);
}
