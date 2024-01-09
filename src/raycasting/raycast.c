#include "cub3d.h"

/**
 * @brief Calcula la posicion y direccion del rayo
*/

void	position_direcction_ray(t_ray *r, int x)
{
	r->camera_x = 2 * x / (double)WIDTH - 1;
	r->ray_dir_x = r->p->dir_x + r->p->plane_x * r->camera_x;
	r->ray_dir_y = r->p->dir_y + r->p->plane_y * r->camera_x;
	if (r->p->dir_x > 0 && r->p->dir_y == 0)
    printf("El jugador está mirando al Este.\n");
	else if (r->p->dir_x < 0 && r->p->dir_y == 0)
		printf("El jugador está mirando al Oeste.\n");
	else if (r->p->dir_x == 0 && r->p->dir_y > 0)
		printf("El jugador está mirando al Norte.\n");
	else if (r->p->dir_x == 0 && r->p->dir_y < 0)
		printf("El jugador está mirando al Sur.\n");
	else
		printf("El jugador está mirando en una dirección no cardinal.\n");
	printf("ray_dir_x: %f, ray_dir_y: %f\n", r->ray_dir_x, r->ray_dir_y);
	printf("plane_x: %f, plane_y: %f\n", r->p->plane_x, r->p->plane_y);
	printf("camera_x: %f\n", r->camera_x);
}
/**
 * @brief Calcula la distancia que recorre el rayo desde una celda a la siguiente
*/

void	delta_dist(t_ray *r)
{
	if (r->ray_dir_x == 0)
		r->delta_dist_x = INFINITE;
	else
		r->delta_dist_x = fabs(1 / r->ray_dir_x);
	if (r->ray_dir_y == 0)
		r->delta_dist_y = INFINITE;
	else
		r->delta_dist_y = fabs(1 / r->ray_dir_y);
	printf("delta_dist_x: %f, delta_dist_y: %f\n", r->delta_dist_x, r->delta_dist_y);
}

/**
 * @brief Calcula la distancia que recorre el rayo desde una celda a la siguiente
*/

void	side_dist(t_ray *r)
{
	if (r->ray_dir_x < 0)
    {
        r->step_x = -1;
        r->side_dist_x = (r->p->px - r->map_x) * r->delta_dist_x;
    }
    else
    {
        r->step_x = 1;
        r->side_dist_x = (r->map_x + 1.0 - r->p->px) * r->delta_dist_x;
    }
    if (r->ray_dir_y < 0)
    {
        r->step_y = -1;
        r->side_dist_y = (r->p->py - r->map_y) * r->delta_dist_y;
    }
    else
    {
        r->step_y = 1;
        r->side_dist_y = (r->map_y + 1.0 - r->p->py) * r->delta_dist_y;
    }
    printf("side_dist_x: %f, side_dist_y: %f\n", r->side_dist_x, r->side_dist_y);
}

/**
 * @brief Realiza el algoritmo DDA
*/

void	perform_dda(t_ray *r)
{
	r->hit = 0;
	while (r->hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (r->m->d->map[r->map_x][r->map_y] != '0')
			r->hit = 1;
	}
	printf("side: %d\n", r->side);
	printf("hit: %d\n", r->hit);
}

/**
 * @brief Calculo de la linea perpendicular a la pared
*/

void	per_wall_dist(t_ray *r)
{
	if (r->side == 0)
		r->perp_wall_dist = r->side_dist_x - r->delta_dist_x;
	else
		r->perp_wall_dist = r->side_dist_y - r->delta_dist_y;
	r->line_height = (int)(HEIGHT / r->perp_wall_dist);
    printf("perp_wall_dist: %f\n", r->perp_wall_dist);
    printf("line_height: %d\n", r->line_height);
}

