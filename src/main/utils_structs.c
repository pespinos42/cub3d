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
	initialize_data(d);
	initialize_map(m);
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
 * @param player_orientation Orientacion del jugador
 * @param found_no Flag para saber si se ha encontrado la textura norte
 * @param path_no Path de la textura norte
 * @param found_so Flag para saber si se ha encontrado la textura sur
 * @param path_so Path de la textura sur
 * @param found_we Flag para saber si se ha encontrado la textura oeste
 * @param path_we Path de la textura oeste
 * @param found_ea Flag para saber si se ha encontrado la textura este
 * @param path_ea Path de la textura este
 * @param found_f Flag para saber si se ha encontrado el color del suelo
 * @param path_f Path del color del suelo
 * @param found_c Flag para saber si se ha encontrado el color del cielo
 * @param path_c Path del color del cielo
 * @param found_map Flag para saber si se ha encontrado el mapa
 * @param row_list Lista de filas
 */

void	initialize_data(t_data *d)
{
	d->flag_char = 0;
	d->number_rows = 0;
	d->x_position_player = -1;
	d->y_position_player = -1;
	d->map = NULL;
	d->player_orientation = '\0';
	d->found_no = 0;
	d->path_no = NULL;
	d->found_so = 0;
	d->path_so = NULL;
	d->found_we = 0;
	d->path_we = NULL;
	d->found_ea = 0;
	d->path_ea = NULL;
	d->found_f = 0;
	d->path_f = NULL;
	d->found_c = 0;
	d->path_c = NULL;
	d->found_map = 0;
	d->row_list = NULL;
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

void	initialize_map(t_map *m)
{
	m->mlx = NULL;
	m->mini = NULL;
	m->mi_bg = NULL;
	m->map = NULL;
	m->clear = NULL;
	m->title = "cub3d";
	m->sky_image = NULL;
	m->floor_image = NULL;
	m->sky_color = get_rgba(m->d->c_r, m->d->c_g, m->d->c_b, 0);//0x87CEEBFF;   // color del cielo
	m->floor_color = get_rgba(m->d->f_r, m->d->f_g, m->d->f_b, 0);//0xFFA07AFF; // color del suelo
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
