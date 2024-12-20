/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_ul_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:24:23 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/20 22:24:24 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long_bonus.h"

void	initialize_structures_player(t_player_move *player)
{
	player->x = 0;
	player->y = 0;
	player->coins = 0;
}

void	initialize_structures_map_size(t_map_size *map_size)
{
	map_size->len_x = 0;
	map_size->len_y = 0;
}
