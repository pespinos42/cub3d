#include "../include/cub3d.h"

/**
 ** @brief Inicializa las estructuras
 * @param d Estructura de los datos
 * @param m Estructura del mapa
 * @param p Estructura del jugador
 */

void	ft_initialize_structs(t_data *d, t_map *m, t_player *p)
{
	m->d = d;
	p->m = m;
	p->d = d;
	ft_initialize_data(d);
	ft_initialize_map(m);
	ft_initialize_player(p);
}

/**
 ** @brief Inicializa la estructura de los datos
 * @param d Estructura de los datos
 * @param flag_char Flag para saber si hay un caracter no permitido
 * @param number_rows Numero de filas del mapa
 * @param x_position_player Posicion del jugador en el eje x
 * @param y_position_player Posicion del jugador en el eje y
 * @param map Mapa
 */

void	ft_initialize_data(t_data *d)
{
	d->flag_char = 0;
	d->number_rows = 0;
	d->x_position_player = -1;
	d->y_position_player = -1;
	d->map = NULL;
	ft_number_rows(d);
	ft_check_characters(d);
	ft_create_map(d);
	ft_check_limits(d);
}

/**
 ** @brief Inicializa la estructura del mapa
 * @param m Estructura del mapa
 * @param mlx Estructura de mlx
 * @param mini Esructura minimapa
 * @param mi_bg Estructura minimapa background
 * @param title Titulo de la ventana
 * @param sky_image Imagen del cielo
 * @param floor_image Imagen del suelo
 * @param bg_image Imagen del fondo
 * @param sky_color Color del cielo
 * @param floor_color Color del suelo
 */

void	ft_initialize_map(t_map *m)
{
	m->mlx = NULL;
	m->mini = NULL;
	m->mi_bg = NULL;
	m->title = "cub3d";
	m->sky_image = NULL;
	m->floor_image = NULL;
	m->bg_image = NULL;
	m->sky_color = 0x87CEEBAA;   // color del cielo
	m->floor_color = 0xFFA07AAA; // color del suelo
}
/**
 ** @brief Inicializa la estructura del jugador
 * @param p Estructura del jugador
 * @param d Estructura de los datos
 * @param m Estructura del mapa
 * @param px Posicion del jugador en el eje x
 * @param py Posicion del jugador en el eje y
 * @param dir_x Direccion del jugador en el eje x
 * @param dir_y Direccion del jugador en el eje y
 * @param plane_x Plano de la camara en el eje x
 * @param plane_y Plano de la camara en el eje y
 * @param camera_x Posicion de la camara en el eje x
 * @param ray_dir_x Direccion del rayo en el eje x
 * @param ray_dir_y Direccion del rayo en el eje y
 * @param map_x Posicion del mapa en el eje x
 * @param map_y Posicion del mapa en el eje y
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
 * @param move_speed Velocidad de movimiento
 * @param rot_speed Velocidad de rotacion
 */

void	ft_initialize_player(t_player *p)
{
	p->px = p->d->x_position_player;
	p->py = p->d->y_position_player;
	p->dir_x = -1;
	p->dir_y = 0;
	p->plane_x = 0;
	p->plane_y = 0.66;
	p->camera_x = 0;
	p->ray_dir_x = 0;
	p->ray_dir_y = 0;
	p->map_x = 0;
	p->map_y = 0;
	p->side_dist_x = 0;
	p->side_dist_y = 0;
	p->delta_dist_x = 0;
	p->delta_dist_y = 0;
	p->perp_wall_dist = 0;
	p->step_x = 0;
	p->step_y = 0;
	p->hit = 0;
	p->side = 0;
	p->line_height = 0;
	p->draw_start = 0;
	p->draw_end = 0;
	p->move_speed = 0.05;
	p->rot_speed = 0.05;
}
