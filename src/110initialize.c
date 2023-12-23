#include "../include/cub3d.h"

void	ft_number_rows(t_data *d)
{
	int	rows;
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
	d->foundNO = 0;
	d->pathNO = NULL;
	d->foundSO = 0;
	d->pathSO = NULL;
	d->foundWE = 0;
	d->pathWE = NULL;
	d->foundEA = 0;
	d->pathEA = NULL;
	d->foundF = 0;
	d->pathF = NULL;
	d->foundC = 0;
	d->pathC = NULL;
	d->foundMap = 0;
	d->row_list = NULL;
	//ft_number_rows(d);
	ft_check_limits(d);	
	//ft_check_characters(d);
}