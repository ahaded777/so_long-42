/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:33:54 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/17 18:33:57 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long_bonus.h"

void	check_map_elements__ul(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'F'
				&& map[i][j] != 'O')
			{
				free_map(map);
				print_message("Error\nThe map contains invalid elements\n", 2);
			}
			j++;
		}
		i++;
	}
}

void	check_double_charagter(int door, int player, char **map)
{
	if (door > 1 && player > 1)
	{
		free_map(map);
		print_message("Error\nMultiple doors and players detected\n",
			2);
	}
	else if (door > 1)
	{
		free_map(map);
		print_message("Error\nMultiple doors (E) detected in the map\n",
			2);
	}
	else if (player > 1)
	{
		free_map(map);
		print_message("Error\nMultiple players (P) detected in the map\n",
			2);
	}
}

void	check_row_elements(char *row, int *door, int *player, int *coin)
{
	int	j;

	j = 0;
	while (row[j])
	{
		if (row[j] == 'E')
			*door += 1;
		if (row[j] == 'P')
			*player += 1;
		if (row[j] == 'C')
			*coin += 1;
		j++;
	}
}

void	ft_check_elements(char **map)
{
	int	i;
	int	door;
	int	coin;
	int	player;

	door = 0;
	coin = 0;
	player = 0;
	i = 0;
	while (map[i])
	{
		check_row_elements(map[i], &door, &player, &coin);
		i++;
	}
	if (!door || !player || !coin)
	{
		free_map(map);
		print_message("Error\nMissing elements in the map\n",
			2);
	}
	check_double_charagter(door, player, map);
	check_map_elements__ul(map);
}
