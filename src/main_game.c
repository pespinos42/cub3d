#include "../include/cub3d.h"

void hook(void *param)
{
	t_map *m;

	m = param;
	if (mlx_is_key_down(m->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(m->mlx);
}

int32_t	ft_main_game(t_map *m, t_player *p)
{
	m->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!m->mlx)
		return (EXIT_FAILURE);
	mlx_set_window_title(m->mlx, m->title);
	//draw_player(m); // Pintar el jugador
	imprimir_variables(m, p);
	map_color_background(m); // Pintar el fondo
	minimap(m, p);  // Pintar el minimapa
	mlx_loop_hook(m->mlx, &hook, m);
	mlx_loop(m->mlx);
	mlx_terminate(m->mlx);
	return (EXIT_SUCCESS);
}
