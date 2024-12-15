/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <aahaded@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:12:25 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/15 22:12:27 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/so_long_bonus.h"

int	ft_check_wall_up(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[0][i])
	{
		if (map[0][i] == '\n')
			return (i);
		if (map[0][i] != '1')
			print_message("Error: The top wall has a problem\n", 2);
		i++;
	}
	return (i);
}

int	ft_check_wall_down(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
		j++;
	j--;
	while (map[j][i])
	{
		if (map[j][i] == '\n' || map[1][i] == '\0')
			return (i);
		if (map[j][i] != '1')
			print_message("Error: The down wall has a problem\n", 2);
		i++;
	}
	return (i);
}

int	ft_check_wall_up_and_down(int len_wall_up, int len_wall_down)
{
	if (len_wall_up != len_wall_down)
		print_message("Error: The up and down wall are not the same\n", 2);
	return (0);
}

int	ft_check_wall_right_and_left(int len_wall, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
		j++;
	j--;
	len_wall--;
	while (map[i])
	{
		if (map[i][len_wall] != '1')
			print_message("Error: The right wall has a problem\n", 2);
		else if (map[i][0] != '1')
			print_message("Error: The left wall has a problem\n", 2);
		i++;
	}
	return (0);
}
