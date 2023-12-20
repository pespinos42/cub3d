#include "cub3d.h"

static void paint_direction(t_map *m, t_bresenham *b)
{
	while (1)
	{
		mlx_put_pixel(m->map, b->x0, b->y0, 0x00FF00);
		if (b->x0 == b->x1 && b->y0 == b->y1)
			break ;
		b->e2 = b->err;
		if (b->e2 > -b->dx)
		{
			b->err -= b->dy;
			b->x0 += b->sx;
		}
		if (b->e2 < b->dy)
		{
			b->err += b->dx;
			b->y0 += b->sy;
		}
	}
}

static void draw_line(t_map *m, t_bresenham *b)
{
	// ft_memset(m->map->pixels, 0, m->map->width * m->map->height * 4);
	b->dx = abs(b->x1 - b->x0);
	b->dy = abs(b->y1 - b->y0);
	if (b->x0 < b->x1)
		b->sx = 1;
	else
		b->sx = -1;
	if (b->y0 < b->y1)
		b->sy = 1;
	else
		b->sy = -1;
	if (b->dx > b->dy)
		b->err = b->dx / 2;
	else
		b->err = -b->dy / 2;
	paint_direction(m, b);
}

void draw_direction_line(t_map *m, t_bresenham *b)
{
	b->end_x = m->p->px + m->p->dir_x * 50;
	b->end_y = m->p->py + m->p->dir_y * 50;
	b->x0 = m->p->px;
	b->y0 = m->p->py;
	b->x1 = b->end_x;
	b->y1 = b->end_y;
	draw_line(m, b);
}



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
	printf("posicion: %f, %f\n", m->p->px, m->p->py);
	printf("angulo rotacion: %f\n", m->p->angle_rot);
	paint_player(m, nx, ny);
	//ft_print_player(m);
}
