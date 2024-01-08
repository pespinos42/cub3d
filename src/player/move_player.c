#include "cub3d.h"

void	move_player(t_map *m, int move, int turn)
{
	int	nx;
	int	ny;

	m->p->move = move;
	m->p->turn = turn;
	//clear_last_position(m);
	// giramos
	m->p->angle_rot += m->p->turn * m->p->rot_speed;
	// actualizamos la dirección
    m->p->dir_x = cos(m->p->angle_rot);
    m->p->dir_y = sin(m->p->angle_rot);
    // avanzamos
    nx = m->p->px + m->p->move * m->p->dir_x * m->p->move_speed;
    ny = m->p->py + m->p->move * m->p->dir_y * m->p->move_speed;
	draw_direction_line(m, m->b);
	m->map_x = nx / BLOCK_SIZE;
	m->map_y = ny / BLOCK_SIZE;
	if (m->d->map[m->map_y][m->map_x] != '1')
	{
		m->p->px = nx;
		m->p->py = ny;
	}
	printf("posicion X: %f, Posicion Y: %f\n", m->p->px, m->p->py);
	printf("angulo rotacion: %f\n", m->p->angle_rot);
	paint_player(m, m->p->px, m->p->py);
	//ft_print_player(m);
}