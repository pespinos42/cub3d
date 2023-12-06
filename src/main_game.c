#include "../include/cub3d.h"

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	(void)param;
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
}

int32_t	ft_main_game(t_data *d)
{
	d->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!d->mlx)
		return (EXIT_FAILURE);
	//mlx_key_hook(d->mlx, &my_keyhook, NULL);
	mlx_loop(d->mlx);
	mlx_terminate(d->mlx);
	return (EXIT_SUCCESS);
}
