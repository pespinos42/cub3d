#include "../include/cub3d.h"

int	ft_check_around(t_data *d, int x, int y)
{
	if (!d->map_flood_fill[x - 1][y] || !d->map_flood_fill[x + 1][y]
			|| !d->map_flood_fill[x][y - 1] || !d->map_flood_fill[x][y + 1]
			|| y > ft_strlen(d->map_flood_fill[x - 1])
			|| y > ft_strlen(d->map_flood_fill[x + 1]))
	{
		printf("POSICION ERRONEA -> [%i][%i]\n", x, y);
		return (0);
	}
	return (1);
}

int	ft_check_outer_walls(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	while (x < d->number_rows)
	{
		y = 0;
		while (d->map_flood_fill[x][y])
		{
			if ((x == 0 || x == d->number_rows - 1))
				if (d->map_flood_fill[x][y] == '#')
					return (0);
			if ((y == 0 || !d->map_flood_fill[x][y + 1]))
				if (d->map_flood_fill[x][y] == '#')
					return (0);
			if (d->map_flood_fill[x][y] == '#')
				if (!ft_check_around(d, x, y))
					return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void	ft_compare_maps(t_data *d)
{
	if (!ft_check_inner_walls(d))
		ft_error_messages(3);
	if (!ft_check_outer_walls(d))
		ft_error_messages(3);
}

void	ft_check_outer_chars(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	while (x < d->number_rows)
	{
		y = 0;
		while (d->map_flood_fill[x][y])
		{
			if (d->map_flood_fill[x][y] != '1'
					&& d->map_flood_fill[x][y] != ' '
					&& d->map_flood_fill[x][y] != '#')
			{
				printf("CARACTER ERROR -> %i\n", d->map_flood_fill[x][y]);
				ft_error_messages(6);
			}
			y++;
		}
		x++;
	}
}

void	ft_check_limits(t_data *d)
{
	ft_check_content_file(d);
	ft_duplicate_map(d);
	ft_locate_player(d);
	ft_flood_fill(d->x_position_player, d->y_position_player, d);
	printf("FLOOD FILL REALIZADO CORRECTAMENTE\n");
	ft_compare_maps(d);
	printf("MAPA CORRECTO\n");
	ft_check_outer_chars(d);
	printf("NO HAY CARACTERES EXTRA MUROS\n");
	ft_print_map(d);
}
