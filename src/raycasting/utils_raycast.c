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
	print_lines(r, x);
}

void	print_lines(t_ray *r, int x)
{
	int	y;

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
