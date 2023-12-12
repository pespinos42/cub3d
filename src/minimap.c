#include "../include/cub3d.h"

void	minimap(t_map *m, t_player *p)
{
	m->mi_bg = mlx_new_image(m->mlx, 200, 200);
	int i = 0;
	int j = 0;
	// esto es el color de cada pixel
	while (i < 200)
	{
		j = 0;
		while (j < 200)
		{
			m->mi_bg->pixels[i * m->mi_bg->width * 4 + j * 4] = 0; 
			m->mi_bg->pixels[i * m->mi_bg->width * 4 + j * 4 + 1] = 0;
			m->mi_bg->pixels[i * m->mi_bg->width * 4 + j * 4 + 2] = 255;
			m->mi_bg->pixels[i * m->mi_bg->width * 4 + j * 4 + 3] = 255;
			j++;
		}
		i++;
	}
	mlx_image_to_window(m->mlx, m->mi_bg, 0, 0);
	//player_position_map(p);
	draw_minimap(m, p);
	//create_minimap(m);
	//draw_player(m);
}

void	player_position_map(t_player *p)
{
	int minimap_x;
	int minimap_y;

	minimap_x = fabs(p->px - WIDTH_MINIMAP / 2);
	minimap_y = fabs(p->py - HEIGHT_MINIMAP / 2);
	/* printf("px: %f\n", p->px);
	printf("py: %f\n", p->py);
	printf("minimap_x: %d\n", minimap_x);
	printf("minimap_y: %d\n", minimap_y); */
}

void	draw_minimap(t_map *m, t_player *p)
{
	int x;
	int y;

	(void)p;
	m->mini = mlx_new_image(m->mlx, 200, 200);
	x = 0;
	while (m->d->map[x])
	{
		y = 0;
		while (m->d->map[x][y])
		{
			if (m->d->map[x][y] == '1')
				draw_block_wall(m, x, y);
			if (m->d->map[x][y] == '0')
				//draw_block_floor(m, x, y);
			if (m->d->map[x][y] == 'N')
				//draw_player(m, x, y);
			y++;
		}
		x++;
	}
	if (mlx_image_to_window(m->mlx, m->mini, 0, 0) == -1)
		ft_error_messages(5);
}

void	draw_block_wall(t_map *m, int x, int y)
{
	int	i;
	int	j;

	m->block_x = 15;
	m->block_y = 15;
	m->mini = mlx_new_image(m->mlx, 200, 200);
	i = 0;
	while (i < m->block_x)
	{
		j = 0;
		while (j < m->block_y)
		{
			mlx_put_pixel(m->mini, x + i, y + j, 0xFF0000FF);
			j++;
		}
		i++;
	}
	if (mlx_image_to_window(m->mlx, m->mini, 0, 0) == -1)
		ft_error_messages(5);
}

void	draw_player(t_map *m)
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
	m->mini = mlx_new_image(m->mlx, 200, 200);
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
