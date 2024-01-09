#include "../include/cub3d.h"

void	ft_duplicate_map(t_data *d)
{
	int	r;

	r = 0;
	d->map_flood_fill = malloc (d->number_rows * sizeof(char *));
	while (r < d->number_rows)
	{
		d->map_flood_fill[r] = ft_strdup(d->map[r]);
		r++;
	}
}

void	ft_flood_fill(int x, int y, t_data *d)
{
	if (x < 0 || y < 0 || x >= d->number_rows || !d->map_flood_fill[x][y]
			|| d->map_flood_fill[x][y] == '1' || d->map_flood_fill[x][y] == '#')
		return ;
	d->map_flood_fill[x][y] = '#';
	ft_flood_fill(x - 1, y, d);
	ft_flood_fill(x + 1, y, d);
	ft_flood_fill(x, y - 1, d);
	ft_flood_fill(x, y + 1, d);
}

void	ft_print_map(t_data *d)
{
	int	r;

	printf("\n");
	r = 0;
	while (r < d->number_rows)
	{
		printf("%s\n", d->map_flood_fill[r]);
		r++;
	}
	printf("\n");
}

void	ft_locate_player(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < d->number_rows)
	{
		while (d->map[x][y])
		{
			if (d->map[x][y] == 'N' || d->map[x][y] == 'S'
					|| d->map[x][y] == 'E' || d->map[x][y] == 'W')
			{
				d->x_position_player = x;
				d->y_position_player = y;
				d->player_orientation = d->map[x][y];
				return ;
			}
			y++;
		}
		y = 0;
		x++;
	}
	ft_error_messages(9);
}

int	ft_check_inner_walls(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	while (x < d->number_rows)
	{
		y = 0;
		while (d->map[x][y])
		{
			if (d->map[x][y] != '0' && d->map[x][y] != 'N'
					&& d->map[x][y] != 'S' && d->map[x][y] != 'E'
					&& d->map[x][y] != 'W')
			{
				if (d->map[x][y] != d->map_flood_fill[x][y])
					return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}
