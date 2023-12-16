#include "cub3d.h"

void	hook(void *param)
{
	t_map	*m;

	m = param;
	if (mlx_is_key_down(m->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(m->mlx);
	/* if (mlx_is_key_down(m->mlx, MLX_KEY_M))
	{
		m->show_map = !m->show_map;
		mlx_delete_image(m->mlx, m->mini);
		if (m->show_map)
		{
			ft_map(m);
			//draw_minimap(m);
			//minimap(m, NULL);
		}
		else
		{
			mlx_delete_image(m->mlx, m->mi_bg);
			ft_window(m);
		}
	} */
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*m;

	m = param;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(m, 1, 0);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(m, 0, -1);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(m, -1, 0);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(m, 0, 1);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		move_player(m, 1, 0);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		move_player(m, 0, -1);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		move_player(m, -1, 0);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		move_player(m, 0, 1);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
	{
		m->show_map = !m->show_map;
		
		if (m->show_map)
		{
			ft_map(m);
			//draw_minimap(m);
			//minimap(m, NULL);
		}
		else
		{
			ft_window(m);
		}
	}
}

int32_t	ft_main_game(t_map *m, t_player *p)
{
	(void)p;
	m->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!m->mlx)
		return (EXIT_FAILURE);
	mlx_set_window_title(m->mlx, m->title);
	mlx_key_hook(m->mlx, &key_hook, m);
	ft_window(m);
	mlx_loop_hook(m->mlx, &hook, m);
	mlx_loop(m->mlx);
	mlx_terminate(m->mlx);
	return (EXIT_SUCCESS);
}
