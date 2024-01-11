#include "cub3d.h"

// MOVE_PLAYER
void	key_hook(mlx_key_data_t keydata, void *param);
void	move_player_map(mlx_key_data_t keydata, t_ray *r);
void	turn_player_map(mlx_key_data_t keydata, t_ray *r);
void	move_player(t_ray *r, float x, float y);