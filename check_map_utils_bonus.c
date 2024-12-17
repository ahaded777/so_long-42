/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <aahaded@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:29:58 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/17 16:30:00 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long_bonus.h"

void	ft_check_map_v1(char **map)
{
	int	i;

	if (!map[0] || !map[0][0] || !map)
		print_message("Error\nempty map file\n", 2);
	i = 0;
	while (map[i])
	{
		if (!map[i])
			print_message("Error\nInvalid map, check your walls\n", 2);
		i++;
	}
}

void	ft_check_wall_right_left(char **map, int len_wall_up)
{
	int	i;

	i = 0;
	len_wall_up -= 2;
	while (map[i])
	{
		if (map[i][len_wall_up] != '1' || map[i][0] != '1')
			print_message("Error\nInvalid map, check your walls\n", 2);
		i++;
	}
}

void	ft_check_wall_up_down(char **map, int len_wall_up)
{
	int	i;
	int	lines;

	i = 0;
	lines = 0;
	ft_check_wall_right_left(map, len_wall_up);
	while (map[lines])
		lines++;
	while (map[0][i] != '\n')
	{
		if (map[0][i] != '1' || map[lines - 1][i] != '1')
			print_message("Error\nInvalid map, check your walls\n", 2);
		i++;
	}
}

void	ft_check_map_walls(char **map)
{
	int	i;
	int	j;
	int	len_wall;
	int	len;

	if (!map[0] || !map[0][0] || !map)
		print_message("Error\nempty map file", 2);
	i = 0;
	j = 0;
	len_wall = 0;
	len = 0;
	while (map[0][len_wall])
		len_wall++;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][len - 1] != '\n')
			len += 1;
		if (len != len_wall)
			print_message("Error\nInvalid map, check your walls\n", 2);
		i++;
	}
	ft_check_wall_up_down(map, len_wall);
}
