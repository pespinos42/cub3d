#include "cub3d.h"

void	move_player_map(mlx_key_data_t keydata, t_map *m)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(m, 1, 0);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(m, 1, 0);
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(m, 1, 0);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(m, 1, 0);
}

void	turn_player_map(mlx_key_data_t keydata, t_map *m)
{
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(m, 0, -1);
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(m, 0, 1);
}

void	move_player(t_map *m, int move, int turn)
{
	(void)move;
	(void)turn;
	(void)m;
}