#include "cub3d.h"

int	ft_check_parameters(t_data *d)
{
	if (d->argc == 2 && ft_strnstr(d->argv[1], ".cub", ft_strlen(d->argv[1])))
	{

		printf("ABRIENDO ARCHIVO...\n");
		return (1);
	}
	else
	{
		printf("ERROR\tDATOS ERRONEOS\n");
		return (-1);
	}
}