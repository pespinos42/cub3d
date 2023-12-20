#include "cub3d.h"

/**
 ** @brief Inicializa las estructuras
 * @param d Estructura de los datos
 * @param m Estructura del mapa
 */

void	init_struct_data_map(t_data *d, t_map *m)
{
	//m->b = b;
	//m->p = p;
	m->d = d;
	//p->m = m;
	//p->d = d;
	ft_initialize_data(d);
	ft_initialize_map(m);
	//ft_bresenham(b);
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
 * @param map_x Posicion del jugador en el mapa en el eje x
 * @param map_y Posicion del jugador en el mapa en el eje y
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
	m->sky_color = 0x87CEEBFF;   // color del cielo
	m->floor_color = 0xFFA07AFF; // color del suelo
	m->start_x = 0;
	m->start_y = 0;
	m->show_map = false;
	m->dx = 5;
	m->dy = 5;
	m->block_center_x = 0;
	m->block_center_y = 0;
	m->player_x = 0;
	m->player_y = 0;
	m->map_x = 0;
	m->map_y = 0;
}
