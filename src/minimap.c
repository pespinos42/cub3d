#include "../include/cub3d.h"

void	minimap(t_map *m, t_player *p)
{
	(void)p;
	m->mi_bg = mlx_new_image(m->mlx, WIDTH_MINIMAP, HEIGHT_MINIMAP);
	int i = 0;
	int j = 0;
	while (i < 200)
	{
		j = 0;
		while (j < 200)
		{
			m->mi_bg->pixels[i * m->mi_bg->width * 4 + j * 4] = 0; 
			m->mi_bg->pixels[i * m->mi_bg->width * 4 + j * 4 + 1] = 0;
			m->mi_bg->pixels[i * m->mi_bg->width * 4 + j * 4 + 2] = 255;
			m->mi_bg->pixels[i * m->mi_bg->width * 4 + j * 4 + 3] = 0;
			j++;
		}
		i++;
	}
	mlx_image_to_window(m->mlx, m->mi_bg, 0, 0);
	//player_position_map(p);
	//create_minimap(m);
	//draw_player(m);
}

void	player_position_map(t_map *m)
{
	int minimap_x;
	int minimap_y;

	minimap_x = abs(m->d->x_position_player - WIDTH_MINIMAP / 2);
	minimap_y = abs(m->d->y_position_player - HEIGHT_MINIMAP / 2);
	/* printf("px: %f\n", p->px);
	printf("py: %f\n", p->py);
	printf("minimap_x: %d\n", minimap_x);
	printf("minimap_y: %d\n", minimap_y); */
}


void	draw_position_player(t_map *m)
{
	int px;
	int py;
	int dx;
	int dy;
	int i;
	int j;

	dx = 5; // Tamaño del "píxel" del jugador o ancho del jugador
	dy = 5; // Tamaño del "píxel" del jugador o alto del jugador
	px = WIDTH_MINIMAP / 2 - dx / 2; // Posición X del jugador en el minimapa
	py = HEIGHT_MINIMAP / 2 - dy / 2; // Posición Y del jugador en el minimapa
	m->mini = mlx_new_image(m->mlx, 15, 15);
	i = 0;
	while (i < dx)
	{
		j = 0;
		while (j < dy)
		{
			mlx_put_pixel(m->mini, px + i, py + j, 0xFF0000FF);
			j++;
		}
		i++;
	}
	if (mlx_image_to_window(m->mlx, m->mini, 0, 0) == -1)
		ft_error_messages(5);
}
