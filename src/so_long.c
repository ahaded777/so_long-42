/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:15:05 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/13 12:13:34 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

int close_window(void *par)
{
    (void)par;
    exit(EXIT_SUCCESS);
    return (0);
}

void print_message(char *message, int fd)
{
    ft_putstr_fd(message, fd);
    if (fd == 2)
        exit(EXIT_FAILURE);
    else
        exit(EXIT_SUCCESS);
}

char **read_map(char *filename)
{
    int     fd_file;
    char    **res_map;
    int     i = 0;
    char    *line;

    fd_file = open(filename, O_RDONLY);
    if (fd_file == -1)
        print_message("Error: opening file", 2);
    res_map = malloc(sizeof(char *) * 100);
    if (!res_map)
        print_message("Error: allocating memory", 2);
    while ((line = get_next_line(fd_file)) != NULL)
    {
        res_map[i] = line;
        i++;
    }
    res_map[i] = NULL;
    close(fd_file);
    return (res_map);
}

void render_map(t_textures textures, t_window *window, t_player_move_and_data player)
{
    int i;
    int j;

    i = 0;
    //printf("cooc: %d\n", window->cox);
    while (window->map[i])
    {
        j = 0;
        while (window->map[i][j])
        {
            if (window->map[i][j] == '1')
                mlx_put_image_to_window(window->mlx, window->mlx_win, textures.wall, j * TILE_SIZE, i * TILE_SIZE); 
            else if (window->map[i][j] == '0')
                mlx_put_image_to_window(window->mlx, window->mlx_win, textures.floor, j * TILE_SIZE, i * TILE_SIZE);
            else if (window->map[i][j] == 'C')
                mlx_put_image_to_window(window->mlx, window->mlx_win, textures.coin, j * TILE_SIZE, i * TILE_SIZE);
            else if (window->map[i][j] == 'E' && window->cox == player.coins)
	    {
                mlx_put_image_to_window(window->mlx, window->mlx_win, textures.exit, j * TILE_SIZE, i * TILE_SIZE);
		printf("opening door\n");
		if (window->map[window->player->y][window->player->x] == 'E')
			exit(EXIT_SUCCESS);
	    }
	    printf("xx: %d\nyy: %d\n", player.x, player.y);
	    if (i == player.y && j == player.x)
                mlx_put_image_to_window(window->mlx, window->mlx_win, textures.player, j * TILE_SIZE, i * TILE_SIZE);
            j++;
        }
        i++;
    }
    //printf("count coin player: %d\n", window->player->coins);
    //printf("count coin map: %d\n", window-);
}

void    size_map(t_window *window, t_map_size *map_size)
{
    int x;
    int y;
    int i;
    int j; 

    x = 0;
    y = 0;
    i = 0; 
    window->cox = 0; 
    while (window->map[i])
    {
	    j = 0;
	    while (window->map[i][j])
	    {
		    if (window->map[i][j] == 'C')
			   window->cox += 1;
		    j++;
	    }
	    i++;
    } 
    while (window->map[y])
    {
	    y++;
    }
    map_size->len_y += y;
    while (window->map[0][x] != '\n')
    {
	    x++;
    }
    map_size->len_x += x;
}

void	eat_coins(t_window *window);

int handle_keypress(int keycode, t_window *window)
{
    t_player_move_and_data *player = window->player;

    if (keycode == ESC_KEY)
        exit(EXIT_SUCCESS);
    if ((keycode == 'D' || keycode == 'd'|| keycode == RIGHT_KEY)
		    && window->map[window->player->y][window->player->x + 1] != '1')
        window->player->x += 1;
    else if ((keycode == 'A' || keycode == 'a'|| keycode == LEFT_KEY) 
		    && window->map[window->player->y][window->player->x - 1] != '1')
        window->player->x -= 1;
    else if ((keycode == 'W' || keycode == 'w'|| keycode == UP_KEY) 
		    && window->map[window->player->y - 1][window->player->x] != '1')
        window->player->y -= 1;
    else if ((keycode == 'S' || keycode == 's'|| keycode == DOWN_KEY) 
		    && window->map[window->player->y + 1][window->player->x] != '1')
        window->player->y += 1;
    mlx_clear_window(window->mlx, window->mlx_win);
    eat_coins(window);
   // printf("count coin: %d\n", window->player->coins);
    render_map(window->textures, window, *player);
    return (0);
}

void	eat_coins(t_window *window)
{
	if (window->map[window->player->y][window->player->x] == 'C')
	{
		window->map[window->player->y][window->player->x] = '0';
		window->player->coins += 1;
	}

}

void	check_player_map(t_window window, t_player_move_and_data *player)
{
	int x;
	int y;

	y = 0;
	while (window.map[y])
	{
		x = 0;
		while (window.map[y][x])
		{
			if (window.map[y][x] == 'P')
			{
				player->x = x;
				player->y = y;
				//printf("x: %d\ny: %d\n", x, y);
			}
			x++;
		}
		y++;
	}
}

int main(int ac, char **av)
{
    t_window        window;
    t_textures      textures;
    t_map_size      map_size;
    t_player_move_and_data   player;

    if (ac != 2)
        print_message("Usage: ./so_long <map_file>\n", 2);
    window.mlx = mlx_init();
    if (!window.mlx)
        print_message("Error: x server\n", 2);
    window.map = read_map(av[1]);
    size_map(&window, &map_size);
    check_player_map(window, &player);
    //player.x = window.player;
    //player.y = 2;
    window.player = &player;
    window.mlx_win = mlx_new_window(window.mlx, map_size.len_x * TILE_SIZE, map_size.len_y * TILE_SIZE, "GTA SAN");
    if (!window.mlx_win)
        print_message("Error: Failed to create window\n", 2);
    textures.wall = mlx_xpm_file_to_image(window.mlx, "./textures/wall.xpm", &window.img_width, &window.img_height);
    textures.floor = mlx_xpm_file_to_image(window.mlx, "./textures/floor.xpm", &window.img_width, &window.img_height);
    textures.player = mlx_xpm_file_to_image(window.mlx, "./textures/player_1.xpm", &window.img_width, &window.img_height);
    textures.coin = mlx_xpm_file_to_image(window.mlx, "./textures/coin.xpm", &window.img_width, &window.img_height);
    textures.exit = mlx_xpm_file_to_image(window.mlx, "./textures/exit.xpm", &window.img_width, &window.img_height);
    if (!textures.wall || !textures.floor || !textures.player || !textures.coin || !textures.exit)
        print_message("Error: Failed to load textures\n", 2);
    window.textures = textures;
    render_map(textures, &window, player);
    mlx_hook(window.mlx_win, 17, 0, close_window, NULL);
    mlx_key_hook(window.mlx_win, handle_keypress, &window);
    mlx_loop(window.mlx);
    exit(EXIT_SUCCESS);
}
