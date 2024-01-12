#include "cub3d.h"

/**
 * @brief Calcular el pixel mas alto y mas bajo para dibujar la pared
 */

void	draw_start_end(t_ray *r)
{
	r->draw_start = ((-1) * r->line_height) / 2 + HEIGHT / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + HEIGHT / 2;
	if (r->draw_end >= HEIGHT)
		r->draw_end = HEIGHT - 1;
	//printf("draw_start: %d, draw_end: %d\n", r->draw_start, r->draw_end);
}

/**
 * @brief Dibujar los pixeles de la pared
 */

void	verline(t_ray *r, int x)
{

	if (r->side == 0)
		r->wall_x = r->p->py + r->perp_wall_dist * r->ray_dir_y;
	else
		r->wall_x = r->p->px + r->perp_wall_dist * r->ray_dir_x;
	r->wall_x -= floor((r->wall_x));
	/* printf("px: %f, py: %f\n", r->p->px, r->p->py);
	printf("wall_x: %f\n", r->wall_x); */
	//check_side(r);
	print_lines(r, x);
}

/**
 * @brief Calcular el lado de la pared
 */

void	check_side(t_ray *r)
{
	if (r->side == 0 && (r->map_x - r->p->px) >= 0)
		r->side += 2;
	if (r->side == 1 && (r->map_y - r->p->py) >= 0)
		r->side += 2;
}

void	print_lines(t_ray *r, int x)
{
	int		y;

	/* printf("x: %d\n", x);
	printf("*************************************************************\n"); */
	y = r->draw_start;
	while (y < r->draw_end)
	{
		mlx_put_pixel(r->wall, x, y, 0x00FFFFFF);
		y++;
	}
}

void	player_orientation(t_map *m, t_player *p)
{
	if (m->d->player_orientation == 'N')
	{
		p->dir_x = -1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = 0.66;
	}
	else if (m->d->player_orientation == 'S')
	{
		p->dir_x = 1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = -0.66;
	}
	else if (m->d->player_orientation == 'E')
	{
		p->dir_x = 0;
		p->dir_y = 1;
		p->plane_x = 0.66;
		p->plane_y = 0;
	}
	else if (m->d->player_orientation == 'W')
	{
		p->dir_x = 0;
		p->dir_y = -1;
		p->plane_x = -0.66;
		p->plane_y = 0;
	}
}
