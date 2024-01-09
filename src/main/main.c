#include "cub3d.h"

int	main(int argc, char **argv)
{
	//atexit(ft_leaks);
	t_data d;
	t_map m;

	atexit(ft_leaks);
	d.argc = argc;
	d.argv = argv;
	if (ft_check_parameters(&d) != 1)
		ft_error_messages(1);
	ft_initialize_data(&d);
	init_struct_data_map(&d, &m);
	ft_main_game(&m);
	ft_free_all(&d);
	return (0);
}