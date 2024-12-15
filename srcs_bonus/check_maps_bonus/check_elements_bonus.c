/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:07:27 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/15 14:07:31 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/so_long.h"

void	check_double_charagter(int door, int player)
{
	if (door > 1 && player > 1)
		print_message("Error: Multiple doors and players detected\n", 2);
	else if (door > 1)
		print_message("Error: Multiple doors (E) detected in the map\n", 2);
	else if (player > 1)
		print_message("Error: Multiple players (P) detected in the map\n", 2);
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

void	ft_check_elements(char *filename)
{
	int		i;
	int		door;
	int		coin;
	int		player;
	char	**map;

	door = 0;
	coin = 0;
	player = 0;
	map = read_map(filename);
	if (!map)
		print_message("Error: Failed to read map\n", 2);
	i = 0;
	while (map[i])
	{
		check_row_elements(map[i], &door, &player, &coin);
		i++;
	}
	if (!door || !player || !coin)
	{
		free_map(map);
		print_message("Error: Missing elements in the map\n", 2);
	}
	check_double_charagter(door, player);
	free_map(map);
}
