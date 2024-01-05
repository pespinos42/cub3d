#include "cub3d.h"

void	ft_window(t_map *m, t_player *p)
{
	t_ray	r;

	ft_initialize_ray(m, p, &r);
	map_color_background(m);
	raycasting(&r);
}

void	raycasting(t_ray *r)
{
	int	x;

	x = 0;
	/* r->wall = mlx_new_image(r->m->mlx, WIDTH, HEIGHT);
	ft_memset(r->wall->pixels, 0, WIDTH * HEIGHT * 4);
	if (mlx_image_to_window(r->m->mlx, r->wall, 0, 0) == -1)
		ft_error_messages(5); */
	while (x < WIDTH)
	{
		//! ... lógica del raycasting
		// Posicion y direccion del rayo
		position_direcction_ray(r, x);
		// Posicion del jugador en el mapa
		r->map_x = (int)r->m->d->x_position_player;
		r->map_y = (int)r->m->d->y_position_player;
		printf("map_x: %d, map_y: %d\n", r->map_x, r->map_y);
		// Calcula la distancia que recorre el rayo desde una celda a la siguiente
		delta_dist(r);
		side_dist(r);
		// Realiza el algoritmo DDA
		perform_dda(r);
		// Calculo de la linea perpendicular a la pared
		per_wall_dist(r);
		// Calcular el pixel mas alto y mas bajo para dibujar la pared
		draw_start_end(r);
		// Dibujar los pixeles de la pared
		verline(r, x);
		x++;
	}
}

void	map_color_background(t_map *map)
{
	uint32_t	x;
	uint32_t	y;

	x = 0;
	y = 0;
	map->sky_image = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	map->floor_image = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	while (x++ < WIDTH)
	{
		y = 0;
		while (y++ < HEIGHT)
		{
			// if (!(x < 200 && y < 200))
			// {
			if (y < HEIGHT / 2)
				mlx_put_pixel(map->sky_image, x, y, map->sky_color);
			else if (y >= HEIGHT / 2)
				mlx_put_pixel(map->floor_image, x, HEIGHT - y,
					map->floor_color);
			// }
		}
	}
	if (mlx_image_to_window(map->mlx, map->sky_image, 0, 0) == -1)
		ft_error_messages(5);
	if (mlx_image_to_window(map->mlx, map->floor_image, 0, HEIGHT / 2) == -1)
		ft_error_messages(5);
}
