#include "cub3d.h"

void	move_player(t_map *m, int dx, int dy)
{
	int nx;
	int ny;
	int map_x;
	int map_y;

	nx = m->p->px + dx * m->p->move_speed;
	ny = m->p->py + dy * m->p->move_speed;
	map_x = nx / BLOCK_SIZE;
	map_y = ny / BLOCK_SIZE;
	if (m->d->map[map_y][map_x] != '1')
	{
		m->p->px = nx;
		m->p->py = ny;
	}
	printf("movimiento: %d, %d\n", dx, dy);
}

