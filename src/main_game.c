#include "../include/cub3d.h"

int32_t	ft_main_game(t_map *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!map->mlx)
		return (EXIT_FAILURE);
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!map->img)
		ft_error_messages(5);
	mlx_set_window_title(map->mlx, map->title);
	/* create_minimap(map);
	draw_player(map); */
	map_color_background(map);
	//background(map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	return (EXIT_SUCCESS);
}
