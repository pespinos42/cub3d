#include "cub3d.h"

void	ft_window(t_map *m, t_player *p)
{
	t_ray	r;

	ft_initialize_ray(m, p, &r);
	map_color_background(m);
	//raycasting(&r);
	//draw_walls(&r);
}

/* void	raycasting(t_ray *r)
{
	int	x;

	x = 0;
	while (x < number_columns(r->m))
	{
		//! ... lógica del raycasting
		
		
		// ... lógica DDA ...
		// ... cálculos de distancia y altura de línea ...
		// ... dibujo en pantalla ...

		x++; 
	}
} */
		/* //! ... manejo de entrada
		//! ... lógica de movimiento y rotación
		if (keyDown(SDLK_UP)) {
		// ... movimiento hacia adelante ...
		}

		if (keyDown(SDLK_DOWN)) {
		// ... movimiento hacia atrás ...
		}

		if (keyDown(SDLK_RIGHT)) {
		// ... rotación a la derecha ...
		}

		if (keyDown(SDLK_LEFT)) {
		// ... rotación a la izquierda ...
		}
		//! ... lógica de temporización
		double time = 0;
		double oldTime = 0;

		// ... cálculos de tiempo y velocidad ... */

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
			// if (!(x < 200 && y < 200))
			// {
				if (y < HEIGHT / 2)
					mlx_put_pixel(map->sky_image, x, y, map->sky_color);
				else if (y >= HEIGHT / 2)
					mlx_put_pixel(map->floor_image, x, HEIGHT - y, map->floor_color);
			// }
		}
	}
	if (mlx_image_to_window(map->mlx, map->sky_image, 0, 0) == -1)
		ft_error_messages(5);
	if (mlx_image_to_window(map->mlx, map->floor_image, 0, HEIGHT / 2) == -1)
		ft_error_messages(5);
}

void	draw_walls(t_ray *r)
{
	int x;

    x = 0;
    while (x < WIDTH)
    {
        // 1. Lanza un rayo desde la posición del jugador
        r = cast_ray(r, x);
		(void)r;

        // 2. Calcula la distancia hasta el primer muro
        /* float wall_dist = calculate_wall_dist(m, &ray);

        // 3. Calcula la altura del muro en la pantalla
        int wall_height = calculate_wall_height(wall_dist);

        // 4. Dibuja el muro en la pantalla
        draw_wall_column(m, x, wall_height); */

        x++;
    }
}

t_ray	*cast_ray(t_ray *r, int x)
{
    // Calcula la dirección del rayo en base a la posición del jugador y la columna de píxeles
    r->ray_dir_x = r->p->dir_x + r->p->plane_x * (2 * x / (double)WIDTH - 1);
    r->ray_dir_y = r->p->dir_y + r->p->plane_y * (2 * x / (double)WIDTH - 1);
	/* printf("ray_dir_x: %f, ray_dir_y: %f\n", r->ray_dir_x, r->ray_dir_y);
	printf("p->dir_x: %f, p->dir_y: %f\n", r->p->dir_x, r->p->dir_y); */

    // Inicializa la posición del rayo a la posición del jugador
    r->map_x = (int)r->p->px;
    r->map_y = (int)r->p->py;
    return (r);
}
