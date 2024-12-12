#include "../includes/so_long.h"

typedef struct s_player {
    int x;
    int y;
} t_player;

void render_map(void *mlx, void *mlx_win, t_textures textures, char **map, t_player player)
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
            else if (i == player.y && j == player.x)
                mlx_put_image_to_window(mlx, mlx_win, textures.player, j * TILE_SIZE, i * TILE_SIZE);
            j++;
        }
        i++;
    }
}

int handle_keypress(int keycode, t_window *window)
{
    t_player *player = window->player;

    if (keycode == 65307)
        exit(0);
    else if (keycode == 'w' && player->y > 0 && window->map[player->y - 1][player->x] != '1') 
        player->y--;
    else if (keycode == 's' && player->y < window->map_size.len_y - 1 && window->map[player->y + 1][player->x] != '1')
        player->y++;
    else if (keycode == 'a' && player->x > 0 && window->map[player->y][player->x - 1] != '1')
        player->x--;
    else if (keycode == 'd' && player->x < window->map_size.len_x - 1 && window->map[player->y][player->x + 1] != '1')
        player->x++;
    mlx_clear_window(window->mlx, window->mlx_win);
    render_map(window->mlx, window->mlx_win, window->textures, window->map, *player);

    return 0;
}

int main(int ac, char **av)
{
    t_window    window;
    t_textures  textures;
    t_player    player;
    t_map_size  map_size;
    char        **map;

    if (ac != 2)
        print_message("Usage: ./so_long <map_file>\n", 2);
    window.mlx = mlx_init();
    if (!window.mlx)
        print_message("Error: x server\n", 2);
    map = read_map(av[1]);
    size_map(map, &map_size);
    window.map = map;
    window.map_size = map_size;
    player.x = 1;
    player.y = 1;
    window.player = &player;
    window.mlx_win = mlx_new_window(window.mlx, map_size.len_x * TILE_SIZE, map_size.len_y * TILE_SIZE, "so_long");
    if (!window.mlx_win)
        print_message("Error: Failed to create window\n", 2);
    textures.wall = mlx_xpm_file_to_image(window.mlx, "./textures/wall.xpm", &window.img_width, &window.img_height);
    textures.floor = mlx_xpm_file_to_image(window.mlx, "./textures/floor.xpm", &window.img_width, &window.img_height);
    textures.player = mlx_xpm_file_to_image(window.mlx, "./textures/player.xpm", &window.img_width, &window.img_height);
    if (!textures.wall || !textures.floor || !textures.player)
        print_message("Error: Failed to load textures\n", 2);
    window.textures = textures;
    render_map(window.mlx, window.mlx_win, textures, map, player);
    mlx_key_hook(window.mlx_win, handle_keypress, &window);
    mlx_loop(window.mlx);
    return 0;
}
