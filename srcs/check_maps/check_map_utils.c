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
#include "../../includes/so_long.h"

// int	ft_check_wall_up(char **map)
// {
// 	int	i;

// 	i = 0;
// 	if (!map)
// 		return (0);
// 	while (map[0][i])
// 	{
// 		if (map[0][i] == '\n')
// 			return (i);
// 		if (map[0][i] != '1')
// 			print_message("Error: The top wall has a problem\n", 2);
// 		i++;
// 	}
// 	return (i);
// }

// int	ft_check_wall_down(char **map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (map[j])
// 		j++;
// 	j--;
// 	while (map[j][i])
// 	{
// 		if (map[j][i] == '\n' || map[1][i] == '\0')
// 			return (i);
// 		if (map[j][i] != '1')
// 			print_message("Error: The down wall has a problem\n", 2);
// 		i++;
// 	}
// 	return (i);
// }

// int	ft_check_wall_up_and_down(int len_wall_up, int len_wall_down)
// {
// 	if (len_wall_up != len_wall_down)
// 		print_message("Error: The up and down wall are not the same\n", 2);
// 	return (0);
// }

// int	ft_check_wall_right_and_left(int len_wall, char **map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (map[j])
// 		j++;
// 	j--;
// 	len_wall--;
// 	while (map[i])
// 	{
// 		if (map[i][len_wall] != '1')
// 			print_message("Error: The right wall has a problem\n", 2);
// 		else if (map[i][0] != '1')
// 			print_message("Error: The left wall has a problem\n", 2);
// 		i++;
// 	}
// 	return (0);
// }


void	ft_check_map_v1(char **map)
{
	int i;

	if (!map[0] || !map[0][0] || !map)
		print_message("\033[0;91mError: empty map file\033[0;39m", 2);
	i = 0;
	if (!map[0] || !map[1] || !map[2])
		print_message("\033[0;91mError\nInvalid map, check your walls\n\033[0;39m", 2);
}

void	ft_check_wall_right_left(char **map, int len_wall_up)
{
	int i;
	
	i = 0;
	len_wall_up -= 2;
	while (map[i])
	{
		if (map[i][len_wall_up] != '1' || map[i][0] != '1')
			print_message("\033[0;91mError\nInvalid map, check your walls\n\033[0;39m", 2);
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
			print_message("\033[0;91mError\nInvalid map, check your walls\n\033[0;39m", 2);
		i++;
	}
}


void	ft_check_map_walls(char **map)
{
	int i;
	int j;
	int len_wall;
	int len;

	if (!map[0] || !map[0][0] || !map)
		print_message("\033[0;91mError: empty map file\033[0;39m", 2);
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
			print_message("\033[0;91mError\nInvalid map, check your walls\n\033[0;39m", 2);
		i++;
	}
	ft_check_wall_up_down(map, len_wall);
}
