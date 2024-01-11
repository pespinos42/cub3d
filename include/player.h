#include "cub3d.h"

// FT_PLAYER
void	move_player(t_map *m, int move, int turn);

// UTILS_PLAYER
void	move_player_map(mlx_key_data_t keydata, t_map *m);
void	turn_player_map(mlx_key_data_t keydata, t_map *m);