#include "cub3d.h"

void	minimap(t_map *m)
{
	int	i;
	int	j;

	m->mi_bg = mlx_new_image(m->mlx, WIDTH_MINIMAP, HEIGHT_MINIMAP);
	i = 0;
	j = 0;
	while (i < 200)
	{
		j = 0;
		while (j < 200)
		{
			m->mi_bg->pixels[i * m->mi_bg->width * 4 + j * 4] = 0;
			m->mi_bg->pixels[i * m->mi_bg->width * 4 + j * 4 + 1] = 0;
			m->mi_bg->pixels[i * m->mi_bg->width * 4 + j * 4 + 2] = 0;
			m->mi_bg->pixels[i * m->mi_bg->width * 4 + j * 4 + 3] = 255;
			j++;
		}
		i++;
	}
	mlx_image_to_window(m->mlx, m->mi_bg, 0, 0);
}

void	centre_player(t_map *m)
{
	m->start_x = m->d->x_position_player - WIDTH_MINIMAP / (2 * BLOCK_SIZE);
	m->start_y = m->d->y_position_player - HEIGHT_MINIMAP / (2 * BLOCK_SIZE);
	if (m->start_x < 0)
		m->start_x = 0;
	if (m->start_y < 0)
		m->start_y = 0;
}

void	draw_blocks(t_map *m, int x, int y)
{
	if (m->d->map[x][y] == '1')
		draw_block_wall(m, (y - m->start_y) * BLOCK_SIZE, (x - m->start_x)
			* BLOCK_SIZE);
	else if (m->d->map[x][y] == '0')
		draw_block_floor(m, (y - m->start_y) * BLOCK_SIZE, (x - m->start_x)
			* BLOCK_SIZE);
	else if (m->d->map[x][y] == 'N' || m->d->map[x][y] == 'S'
		|| m->d->map[x][y] == 'E' || m->d->map[x][y] == 'W')
		draw_player(m, (y - m->start_y) * BLOCK_SIZE, (x - m->start_x)
			* BLOCK_SIZE);
}

void	center_player_block(t_map *m, int x, int y)
{
	m->block_center_x = x + BLOCK_SIZE / 2.0;
	m->block_center_y = y + BLOCK_SIZE / 2.0;
	m->player_x = m->block_center_x - m->dx / 2.0;
	m->player_y = m->block_center_y - m->dy / 2.0;
	m->p->px = m->player_x;
	m->p->py = m->player_y;
	//paint_player(m, m->player_x, m->player_y);
}

