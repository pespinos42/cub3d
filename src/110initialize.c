#include "../include/cub3d.h"

void	ft_number_rows(t_data *d)
{
	int		rows;
	char	*str;

	d->fd = open(d->argv[1], O_RDONLY);
	rows = 0;
	str = ft_get_next_line(d->fd);
	while (str != NULL)
	{
		rows++;
		free (str);
		str = ft_get_next_line(d->fd);
	}
	free (str);
	d->number_rows = rows;
	close(d->fd);
}

void	ft_initialize_map(t_data *d, char **map)
{
	int	r;

	r = 0;
	while (r < d->number_rows)
	{
		map[r] = NULL;
		r++;
	}
}

void	ft_initialize_data(t_data *d)
{
	d->flag_char = 0;
	d->number_rows = 0;
	d->x_position_player = -1;
	d->y_position_player = -1;
	d->map = NULL;
	d->found_no = 0;
	d->path_no = NULL;
	d->found_so = 0;
	d->path_so = NULL;
	d->found_we = 0;
	d->path_we = NULL;
	d->found_ea = 0;
	d->path_ea = NULL;
	d->found_f = 0;
	d->path_f = NULL;
	d->found_c = 0;
	d->path_c = NULL;
	d->found_map = 0;
	d->row_list = NULL;
	ft_check_limits(d);
}
