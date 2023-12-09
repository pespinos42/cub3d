#include "../include/cub3d.h"

void	minimap(t_map *m)
{
	/* m->mi_bg = mlx_new_image(m->mlx, 150, 150);
	ft_memset(m->mi_bg->pixels, 200, m->mi_bg->width * m->mi_bg->height * BPP);
	mlx_image_to_window(m->mlx, m->mi_bg, 0, 0); */
	create_minimap(m);
}

void	create_minimap(t_map *map)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	dx;
	uint32_t	dy;
	uint32_t	i;
	uint32_t	j;

	map->mini = mlx_new_image(map->mlx, 150, 150);
	dx = 30;
	dy = 30;
	y = 0;
	while (map->data->map[y])
	{
		x = 0;
		while (map->data->map[y][x] != '\0')
		{
			i = 0;
			while (i < dx)
			{
				j = 0;
				while (j < dy)
				{
					if (map->data->map[y][x] == '1')
						ft_memset(map->mini->pixels + ((y * dy + j)
								* map->mini->width + x * dx + i) * BPP,
							0x00FFFFFF, BPP);
					else if (map->data->map[y][x] == '0')
						ft_memset(map->mini->pixels + ((y * dy + j)
								* map->mini->width + x * dx + i) * BPP,
							0x00000000, BPP);
					j++;
				}
				i++;
			}
			x++;
		}
		y++;
	}
	mlx_image_to_window(map->mlx, map->mini, 0, 0);
}

void	draw_player(t_map *m)
{
	int px;
	int py;
	int dx;
	int dy;
	int i;
	int j;

	px = 0;
	py = 360; //si Height es 720, entonces 100 es 1/7 de la altura
	dx = 10; // Tamaño del "píxel" del jugador
	dy = 10; // Tamaño del "píxel" del jugador
	m->mini = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	i = 0;
	while (i < dx)
	{
		j = 0;
		while (j < dy)
		{
			mlx_put_pixel(m->mini, px + i, py + j, 0xFF0000FF);
				// Dibuja un cuadrado de píxeles
			j++;
		}
		i++;
	}
	if (mlx_image_to_window(m->mlx, m->mini, 0, 0) == -1)
		ft_error_messages(5);
}