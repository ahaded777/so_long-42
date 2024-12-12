/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:15:05 by aahaded           #+#    #+#             */
/*   Updated: 2024/12/12 16:33:56 by aahaded          ###   ########.fr       */
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

void render_map(void *mlx, void *mlx_win, t_textures textures, char **map, t_player_move player)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1')
                mlx_put_image_to_window(mlx, mlx_win, textures.wall, j * TILE_SIZE, i * TILE_SIZE); 
            else if (map[i][j] == '0')
                mlx_put_image_to_window(mlx, mlx_win, textures.floor, j * TILE_SIZE, i * TILE_SIZE);
            else if (map[i][j] == 'C')
                mlx_put_image_to_window(mlx, mlx_win, textures.coin, j * TILE_SIZE, i * TILE_SIZE);
            else if (map[i][j] == 'E')
                mlx_put_image_to_window(mlx, mlx_win, textures.exit, j * TILE_SIZE, i * TILE_SIZE);
            if (i == player.y && j == player.x)
                mlx_put_image_to_window(mlx, mlx_win, textures.player, j * TILE_SIZE, i * TILE_SIZE);
            j++;
        }
        i++;
    }
}

void    size_map(char **map, t_map_size *map_size)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (map[y])
    {
        y++;
    }
    map_size->len_y = y;
    while (map[0][x] != '\n')
    {
        x++;
    }
    map_size->len_x = x;
}

int handle_keypress(int keycode, t_window *window)
{
    t_player_move *player = window->player;

    if (keycode == ESC_KEY)
        exit(EXIT_SUCCESS);
    if (keycode == 'D' || keycode == 'd'|| keycode == RIGHT_KEY)
        window->player->x += 1;
    else if (keycode == 'A' || keycode == 'a'|| keycode == LEFT_KEY)
        window->player->x -= 1;
    else if (keycode == 'W' || keycode == 'w'|| keycode == UP_KEY)
        window->player->y -= 1;
    else if (keycode == 'S' || keycode == 's'|| keycode == DOWN_KEY)
        window->player->y += 1;
    mlx_clear_window(window->mlx, window->mlx_win);
    render_map(window->mlx, window->mlx_win, window->textures, window->map, *player);
    return (0);
}

int main(int ac, char **av)
{
    t_window        window;
    t_textures      textures;
    t_map_size      map_size;
    t_player_move   player;

    if (ac != 2)
        print_message("Usage: ./so_long <map_file>\n", 2);
    window.mlx = mlx_init();
    if (!window.mlx)
        print_message("Error: x server\n", 2);
    window.map = read_map(av[1]);
    size_map(window.map, &map_size);
    player.x = 1;
    player.y = 1;
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
    render_map(window.mlx, window.mlx_win, textures, window.map, player);
    mlx_hook(window.mlx_win, 17, 0, close_window, NULL);
    mlx_key_hook(window.mlx_win, handle_keypress, &window);
    mlx_loop(window.mlx);

    exit(EXIT_SUCCESS);
}
