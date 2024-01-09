#include "cub3d.h"

/************************* RAYCAST *******************************/

// FT_WINDOW
void	ft_window(t_map *m, t_player *p);
void	map_color_background(t_map *map);
void	raycasting(t_ray *r);
int		get_rgba(int r, int g, int b, int a);

// RAYCAST
void	position_direcction_ray(t_ray *r, int x);
void	delta_dist(t_ray *r);
void	side_dist(t_ray *r);
void	perform_dda(t_ray *r);
void	per_wall_dist(t_ray *r);

// UTILS_RAYCAST
void	draw_start_end(t_ray *r);
void	verline(t_ray *r, int x);
void	check_side(t_ray *r);
void	print_lines(t_ray *r, int x);
void	player_orientation(t_map *m, t_player *p);