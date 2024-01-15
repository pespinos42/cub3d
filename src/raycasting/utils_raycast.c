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
	coordinate_texture(r);
	check_side(r);
	print_lines(r, x);
}

void	print_lines(t_ray *r, int x)
{
	int		y;
	uint8_t	*p;
	int		side;

	side = r->side;
	r->tx = (int)(r->text_coord * (double)r->texs[side]->width);
	r->tx = r->texs[side]->width - r->tx - 1;
	r->step = 1.0 * r->texs[side]->height / r->line_height;
	r->tpos = (r->draw_start - HEIGHT / 2 + r->line_height / 2) * r->step;
	y = r->draw_start;
	while (y < r->draw_end)
	{
		r->ty = (int)r->tpos;
		r->tpos += r->step;
		p = &r->texs[side]->pixels[r->texs[r->side]->width * r->ty * 4 + r->tx * 4];
		r->color = (p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]);
		mlx_put_pixel(r->wall, x, y, r->color);
		y++;
	}
	/* int	y;

	y = r->draw_start;
	while (y < r->draw_end)
	{
		mlx_put_pixel(r->wall, x, y, 0x00FFFFFF);
		y++;
	} */
}

/**
 * @brief Calcular la direccion de la camara
 */

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
