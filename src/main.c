#include "cub3d.h"

void	ft_leaks(void)
{
	system("leaks -q cub3d");
}

int main(int argc, char **argv)
{
	//atexit(ft_leaks);
	t_data	d;
	t_map	m;
	t_player	p;

	d.argc = argc;
	d.argv = argv;
	if (ft_check_parameters(&d) != 1)
		ft_error_messages(1);
	ft_initialize_structs(&d, &m, &p);
	ft_main_game(&m, &p);
	ft_free_all(&d);
	return (0);
}