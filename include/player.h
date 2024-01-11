#include "cub3d.h"

// MOVE_PLAYER
void	move_hook(mlx_key_data_t keydata, void *param);
//void	move_player(t_ray *m, int move, int turn);

// UTILS_PLAYER
void	move_player_map(mlx_key_data_t keydata, t_map *m);
void	turn_player_map(mlx_key_data_t keydata, t_map *m);