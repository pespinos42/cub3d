#include "cub3d.h"

void	hook(void *param)
{
	t_map	*m;

	m = param;
	if (mlx_is_key_down(m->mlx, MLX_KEY_ESCAPE))
		exit(0); // mlx_close_window(m->mlx);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*m;

	m = param;
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(m, 0, 1);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(m, 0, -1);
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(m, 1, 0);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(m, -1, 0);
	// if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
	// 	ft_paint_map(m);
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_PRESS)
		m->map->enabled = 0;
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_PRESS)
		m->map->enabled = 1;
}

// void	ft_paint_map(t_map *m)
// {
// 	m->show_map = !m->show_map;
// 	if (m->show_map)
// 	{
// 		ft_map(m);
// 		// center_player_block(m);
// 		// draw_minimap(m);
// 		//minimap(m, NULL);
// 	}
// 	else
// 	{
// 		ft_window(m, m->p);
// 	}
// }

int32_t	ft_main_game(t_map *m)
{
	t_player	p;
	t_bresenham	b;

	ft_initialize_player(m, &p);
	ft_bresenham(m, &b);
	m->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!m->mlx)
		return (EXIT_FAILURE);
	mlx_set_window_title(m->mlx, m->title);
	mlx_key_hook(m->mlx, &key_hook, m);
	ft_window(m, &p);
	ft_map(m);
	m->map->enabled = 0;
	paint_player(m, m->p->px, m->p->py);
	mlx_loop_hook(m->mlx, &hook, m);
	mlx_loop(m->mlx);
	mlx_terminate(m->mlx);
	return (EXIT_SUCCESS);
}
