/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:07:40 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/14 20:26:29 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long.h"

void	ft_check_map_v1(char **map)
{
	int	i;

	if (!map[0] || !map[0][0] || !map)
		print_message("Error: empty map file\n", 2);
	i = 0;
	if (!map[0] || !map[1] || !map[2])
		print_message("Error\nInvalid map, check your walls\n", 2);
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
		print_message("Error: empty map file", 2);
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
