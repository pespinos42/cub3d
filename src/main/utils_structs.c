#include "cub3d.h"

/**
 ** @brief Inicializa las estructuras
 * @param d Estructura de los datos
 * @param m Estructura del mapa
 * @param p Estructura del jugador
 */

void	ft_initialize_structs(t_data *d, t_map *m, t_player *p, t_bresenham *b)
{
	m->b = b;
	m->p = p;
	m->d = d;
	p->m = m;
	p->d = d;
	ft_initialize_data(d);
	ft_initialize_map(m);
	ft_initialize_player(p);
	ft_bresenham(b);
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
 * @param start_x Posicion de inicio en el eje x
 * @param start_y Posicion de inicio en el eje y
 * @param show_map Si se muestra el mapa
 * @param prev_m_key_state Si se ha pulsado la tecla m
 * @param block_center_x Centro del bloque en el eje x
 * @param block_center_y Centro del bloque en el eje y
 * @param player_x Posicion del jugador en el eje x
 * @param player_y Posicion del jugador en el eje y
 * @param dx Ancho del bloque
 * @param dy Alto del bloque
 */

void	ft_initialize_map(t_map *m)
{
	m->mlx = NULL;
	m->mini = NULL;
	m->mi_bg = NULL;
	m->map = NULL;
	m->clear = NULL;
	m->title = "cub3d";
	m->sky_image = NULL;
	m->floor_image = NULL;
	m->bg_image = NULL;
	m->sky_color = 0x87CEEBFF;   // color del cielo
	m->floor_color = 0xFFA07AFF; // color del suelo
	m->start_x = 0;
	m->start_y = 0;
	m->show_map = false;
	m->dx = 0;
	m->dy = 0;
	m->block_center_x = 0;
	m->block_center_y = 0;
	m->player_x = 0;
	m->player_y = 0;
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

void	ft_initialize_player(t_player *p)
{
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
