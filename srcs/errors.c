/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 22:46:02 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/16 22:46:34 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void    ft_check_filename(char *filename)
{
    char **split_filename;

    split_filename = ft_split(filename, '.');
    if (split_filename[1] == NULL || ft_strncmp(split_filename[1], "ber", ft_strlen(split_filename[1])) != 0)
    {
        free_map(split_filename);
        print_message("\033[0;91mError\nInvalid file extension. Expected '.ber'.\n\033[0;39m", 2);
    }
    free_map(split_filename);
}