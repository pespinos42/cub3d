#include "cub3d.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_ray	*r;

	r = (t_ray *)param;
	mlx_delete_image(r->m->mlx, r->wall);
	move_player_map(keydata, r);
	raycasting(r);
}

void	move_player_map(mlx_key_data_t keydata, t_ray *r)
{
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(r, 1, 0);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(r, -1, 0);
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(r, 0, 1);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(r, 0, -1);
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		turn_player(r, 1);
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		turn_player(r, -1);
}
