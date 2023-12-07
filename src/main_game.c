#include "../include/cub3d.h"

/* static int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
} */

static void background(t_map *m)
{
	memset(m->img->pixels + m->img->width * m->img->height, 224, m->img->width * m->img->height * BPP);
	memset(m->img->pixels, 100, m->img->width * m->img->height / 2 * BPP);

    mlx_image_to_window(m->mlx, m->img, 0, 0);
}

void map_color_background(t_map *map)
{
	uint32_t x;
	uint32_t y;

	x = 0;
	y = 0;
	map->sky_image = mlx_new_image(map->mlx, WIDTH, HEIGHT / 2);
	map->floor_image = mlx_new_image(map->mlx, WIDTH, HEIGHT / 2);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(map->sky_image, x, y, map->sky_color);
			else
				mlx_put_pixel(map->floor_image, x, y - HEIGHT / 2, map->floor_color);
			y++;
		}
		x++;
	}
	mlx_image_to_window(map->mlx, map->sky_image, 0, 0);
	//mlx_image_to_window(map->mlx, map->floor_image, 0, HEIGHT / 2);
	if (mlx_image_to_window(map->mlx, map->img, 0, 0) == -1)
		ft_error_messages(5);
}

int32_t	ft_main_game(t_map *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!map->mlx)
		return (EXIT_FAILURE);
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!map->img)
		ft_error_messages(5);
	map_color_background(map);
	background(map);
	mlx_set_window_title(map->mlx, map->title);
	/* draw_player(d); */
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	return (EXIT_SUCCESS);
}
