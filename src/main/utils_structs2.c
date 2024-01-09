#include "cub3d.h"

/**
 ** @brief Inicializa la estructura del jugador
 * @param p Estructura del jugador
 * @param d Estructura de los datos
 * @param m Estructura del mapa
 * @param px Posicion del jugador en el eje x
 * @param py Posicion del jugador en el eje y
 * @param dir_x Direccion del jugador en el eje x
 * @param dir_y Direccion del jugador en el eje y
 * @param old_dir_x Direccion anterior del jugador en el eje x
 * @param old_dir_y Direccion anterior del jugador en el eje y
 * @param plane_x Plano de la camara en el eje x
 * @param plane_y Plano de la camara en el eje y
 * @param move_speed Velocidad de movimiento en pixeles
 * @param rot_speed Velocidad de rotacion en radianes
 * @param move Si se esta moviendo, 0 = no se mueve, 1 = adelante y -1 = atras
 * @param turn Si se esta girando, 0 = no se mueve, 1 = derecha y -1 = izquierda
 * @param angle_rot Angulo de rotacion
 */

void	ft_initialize_player(t_map *m, t_player *p)
{
	m->p = p;
	p->m = m;
	p->d = m->d;
	p->px = p->d->x_position_player;
	p->py = p->d->y_position_player;
	p->dir_x = -1;
	p->dir_y = 0;
	p->plane_x = 0;
	p->plane_y = 0.66;
	p->old_dir_x = 0;
	p->old_dir_y = 0;
	p->move_speed = 3;
	p->pi = acos(-1.0);
	p->rot_speed = (p->pi / 180) * 3;
	p->angle_rot = 0;
	p->move = 0;
	p->turn = 0;
}

/**
 ** @brief Estructura del raycasting
 * @param camera_x Posicion de la camara en el eje x
 * @param ray_dir_x Direccion del rayo en el eje x
 * @param ray_dir_y Direccion del rayo en el eje y
 * @param map_x Posicion del rayo en el mapa en el eje x
 * @param map_y Posicion del rayo en el mapa en el eje y
 * @param side_dist_x Distancia del rayo en el eje x
 * @param side_dist_y Distancia del rayo en el eje y
 * @param delta_dist_x Distancia del rayo en el eje x
 * @param delta_dist_y Distancia del rayo en el eje y
 * @param perp_wall_dist Distancia de la pared perpendicular
 * @param step_x Paso del rayo en el eje x
 * @param step_y Paso del rayo en el eje y
 * @param hit Si el rayo ha chocado con una pared
 * @param side Si el rayo ha chocado con una pared en el eje x o en el eje y
 * @param line_height Altura de la linea que se va a pintar
 * @param draw_start Donde empieza a pintar la linea
 * @param draw_end Donde termina de pintar la linea
 * @param wall_x Posicion de la pared en el eje x
 */

void	ft_initialize_ray(t_map *m, t_player *p, t_ray *r)
{
	r->p = p;
	r->m = m;
	r->wall = NULL;
	r->camera_x = 0;
	r->ray_dir_x = 0;
	r->ray_dir_y = 0;
	r->map_x = 0;
	r->map_y = 0;
	r->side_dist_x = 0;
	r->side_dist_y = 0;
	r->delta_dist_x = 0;
	r->delta_dist_y = 0;
	r->perp_wall_dist = 0;
	r->step_x = 0;
	r->step_y = 0;
	r->hit = 0;
	r->side = 0;
	r->line_height = 0;
	r->draw_start = 0;
	r->draw_end = 0;
	r->columns = number_colums(m);
	r->wall_x = 0;
}

/**
 * @brief Inicializa la estructura de bresenham
 * @param b Estructura de bresenham
 * @param end_x Posicion final en el eje x de la linea de direccion
 * @param end_y Posicion final en el eje y de la linea de direccion
 * @param dx diferencia absoluta en el eje x entre el punto inicial y el final
 * @param dy diferencia absoluta en el eje y entre el punto inicial y el final
 * @param sx Signo de la diferencia en el eje x
 * @param sy Signo de la diferencia en el eje y
 * @param err Error
 * @param e2 Error 2 temporal
 * @param x0 Posicion inicial en el eje x de la linea de direccion
 * @param y0 Posicion inicial en el eje y de la linea de direccion
 * @param x1 Posicion final en el eje x de la linea de direccion
 * @param y1 Posicion final en el eje y de la linea de direccion
*/

void	ft_bresenham(t_map *m, t_bresenham *b)
{
	m->b = b;
	b->end_x = 0;
	b->end_y = 0;
	b->dx = 0;
	b->dy = 0;
	b->sx = 0;
	b->sy = 0;
	b->err = 0;
	b->e2 = 0;
	b->x0 = 0;
	b->y0 = 0;
	b->x1 = 0;
	b->y1 = 0;
}
