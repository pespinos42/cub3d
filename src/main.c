#include "../include/cub3d.h"

void	ft_leaks(void)
{
	system("leaks -q cub3d");
}

int	main(int argc, char **argv)
{
	t_data	d;

	atexit(ft_leaks);
	d.argc = argc;
	d.argv = argv;
	if (ft_check_parameters(&d) != 1)
		ft_error_messages(1);
	ft_initialize_data(&d);
	ft_free_all(&d);
	printf("\n\nTODO OK\n\n");
	return (0);
}
