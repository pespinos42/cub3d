#include "cub3d.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_ray	*r;

	r = (t_ray *)param;
	move_player_map(keydata, r);
	turn_player_map(keydata, r);
}

void	move_player_map(mlx_key_data_t keydata, t_ray *r)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(r, 0.3, 0);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(r, -0.3, 0);
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(r, 0, 0.3);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(r, 0, -0.3);
}

void	turn_player_map(mlx_key_data_t keydata, t_ray *r)
{
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(r, 0, -1);
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(r, 0, 1);
}

void	move_player(t_ray *r, float x, float y)
{
	r->p->px = r->p->px + x + y;
	r->p->py = r->p->py + x + y;
	raycasting(r);
}