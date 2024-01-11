#include "cub3d.h"

void	exit_hook(void *param)
{
	t_map	*m;

	m = param;
	if (mlx_is_key_down(m->mlx, MLX_KEY_ESCAPE))
		exit(0);
}

void	move_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*m;

	m = param;
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

int32_t	start_game(t_map *m)
{
	t_player	p;

	init_struct_player(m, &p);
	m->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!m->mlx)
		return (EXIT_FAILURE);
	mlx_set_window_title(m->mlx, m->title);
	mlx_key_hook(m->mlx, &move_hook, m);
	ft_window(m, &p);
	mlx_loop_hook(m->mlx, &exit_hook, m);
	mlx_loop(m->mlx);
	mlx_terminate(m->mlx);
	return (EXIT_SUCCESS);
}
