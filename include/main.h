#include "cub3d.h"

// LEAKS.C
void	ft_leaks(void);

// MAIN
int32_t	start_game(t_map *map);
void	exit_hook(void *param);

// INITS_STRUCTS
void	init_structs(t_data *d, t_map *m);
void	init_struct_data(t_data *d);
void	init_struct_map(t_map *m);
void	init_struct_player(t_map *m, t_player *p);
void	init_struct_ray(t_map *m, t_player *p, t_ray *r);
