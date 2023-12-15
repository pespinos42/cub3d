#include "../include/cub3d.h"

void	map_color_background(t_map *map)
{
	uint32_t x;
	uint32_t y;

	x = 0;
	y = 0;
	map->sky_image = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	map->floor_image = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	while (x++ < WIDTH)
	{
		y = 0;
		while (y++ < HEIGHT)
		{
			if (!(x < 200 && y < 200))
			{
				if (y < HEIGHT / 2)
					mlx_put_pixel(map->sky_image, x, y, map->sky_color);
				else if (y >= HEIGHT / 2)
					mlx_put_pixel(map->floor_image, x, HEIGHT - y, map->floor_color);
			}
		}
	}
	if (mlx_image_to_window(map->mlx, map->sky_image, 0, 0) == -1)
		ft_error_messages(5);
	if (mlx_image_to_window(map->mlx, map->floor_image, 0, HEIGHT / 2) == -1)
		ft_error_messages(5);
}
