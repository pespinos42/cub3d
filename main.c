#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data	d;

	d.argc = argc;
	d.argv = argv;
	if (ft_check_parameters(&d) != 1)
		ft_error_messages(1);
	ft_initialize_data(&d);
	

	return (0);
}