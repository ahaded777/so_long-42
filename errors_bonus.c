/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <aahaded@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:30:25 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/17 16:30:27 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long_bonus.h"

void	print_message(char *message, int fd)
{
	ft_putstr_fd("\033[0;91m", fd);
	ft_putstr_fd(message, fd);
	ft_putstr_fd("\033[0;39m", fd);
	if (fd == 2)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}

void	ft_check_filename(char *filename)
{
	char	**split_filename;

	split_filename = ft_split(filename, '.');
	if (split_filename[1] == NULL || ft_strncmp(split_filename[1], "ber",
			ft_strlen(split_filename[1])) != 0)
	{
		free_map(split_filename);
		print_message("Error\nInvalid file extension. Expected '.ber'.\n",
			2);
	}
	free_map(split_filename);
}
