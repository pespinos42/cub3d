#include "cub3d.h"

void	move_player(t_map *m, int dx, int dy)
{
	int	nx;
	int	ny;
	int	map_x;
	int	map_y;

	clear_last_position(m);
	printf("movimiento: %d, %d\n", dx, dy);
	printf("posicion: %f, %f\n", m->p->px, m->p->py);
	nx = m->p->px + dx * m->p->move_speed;
	ny = m->p->py + dy * m->p->move_speed;
	map_x = nx / BLOCK_SIZE;
	map_y = ny / BLOCK_SIZE;
	if (m->d->map[map_y][map_x] != '1')
	{
		m->p->px = nx;
		m->p->py = ny;
	}
	paint_player(m, nx, ny);
}

void	clear_last_position(t_map *m)
{
	int	i;
	int	j;

	printf("posicion: %f, %f\n", m->p->px, m->p->py);
	printf("dx: %d, dy: %d\n", m->dx, m->dy);
	i = m->p->px - m->dx / 2.0;
	while (i < m->p->px + m->dx / 2.0 + 5)
	{
		j = m->p->py - m->dy / 2.0;
		while (j < m->p->py + m->dy / 2.0 + 5)
		{
			mlx_put_pixel(m->map, i, j, 0x00FFFF);
			j++;
		}
		i++;
	}
}
