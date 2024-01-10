#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data d;
	t_map m;

	//atexit(ft_leaks);
	d.argc = argc;
	d.argv = argv;
	if (ft_check_parameters(&d) != 1)
		ft_error_messages(1);
	init_struct_data_map(&d, &m);
	ft_check_limits(&d);
	ft_main_game(&m);
	ft_free_all(&d);
	return (0);
}