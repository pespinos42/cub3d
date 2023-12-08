#include "../include/cub3d.h"

static void hook(void *param)
{
	t_map *m;

	m = param;
	if (mlx_is_key_down(m->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(m->mlx);
}

int32_t	ft_main_game(t_map *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!map->mlx)
		return (EXIT_FAILURE);
	mlx_set_window_title(map->mlx, map->title);
	//background(map);  // Pintar el fondo
	//draw_player(map); // Pintar el jugador
	map_color_background(map);
	mlx_loop_hook(map->mlx, &hook, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	return (EXIT_SUCCESS);
}
