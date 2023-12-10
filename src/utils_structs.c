#include "../include/cub3d.h"

void	ft_initialize_structs(t_data *d, t_map *m, t_player *p)
{
	m->d = d;
	p->m = m;
	p->d = d;
	ft_initialize_data(d);
	ft_initialize_map(m);
	ft_initialize_player(p);
}

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

void	ft_initialize_map(t_map *m)
{
	m->mlx = NULL;
	m->mini = NULL;
	m->mi_bg = NULL;
	m->title = "cub3d";
	m->px = 0;
	m->py = 0;
	m->sky_image = NULL;
	m->floor_image = NULL;
	m->bg_image = NULL;
	m->sky_color = 0x87CEEBAA;   //color del cielo
	m->floor_color = 0xFFA07AAA; //color del suelo
}

void	ft_initialize_player(t_player *p)
{
	p->px = p->d->x_position_player; //posicion del jugador en el eje x
	p->py = p->d->y_position_player; //posicion del jugador en el eje y
	p->dir_x = -1; //direccion del jugador en el eje x
	p->dir_y = 0; //direccion del jugador en el eje y
	p->plane_x = 0; //plano de la camara en el eje x
	p->plane_y = 0.66; //plano de la camara en el eje y
	p->camera_x = 0; //posicion de la camara en el eje x
	p->ray_dir_x = 0; //direccion del rayo en el eje x
	p->ray_dir_y = 0; //direccion del rayo en el eje y
	p->map_x = 0; //posicion del mapa en el eje x
	p->map_y = 0; //posicion del mapa en el eje y
	p->side_dist_x = 0; //distancia del rayo en el eje x
	p->side_dist_y = 0; //distancia del rayo en el eje y
	p->delta_dist_x = 0; //distancia del rayo en el eje x
	p->delta_dist_y = 0; //distancia del rayo en el eje y
	p->perp_wall_dist = 0; //distancia de la pared perpendicular
	p->step_x = 0; //paso del rayo en el eje x
	p->step_y = 0; //paso del rayo en el eje y
	p->hit = 0; //si el rayo ha chocado con una pared
	p->side = 0; //si el rayo ha chocado con una pared en el eje x o en el eje y
	p->line_height = 0; //altura de la linea que se va a pintar
	p->draw_start = 0; //donde empieza a pintar la linea
	p->draw_end = 0; //donde termina de pintar la linea
	p->move_speed = 0.05; //velocidad de movimiento
	p->rot_speed = 0.05; //velocidad de rotacion
}
