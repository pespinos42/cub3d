#include "cub3d.h"

// FT_WINDOW
void	ft_window(t_map *m, t_player *p);
void	map_color_background(t_map *map);
void	raycasting(t_ray *r);
void	draw_walls(t_ray *r);
t_ray	*cast_ray(t_ray *r, int x);

// RAYCAST
void	position_direcction_ray(t_ray *r);