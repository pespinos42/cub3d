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

void	ft_create_map(t_data *d)
{
	int		r;
	char	*str;

	d->fd = open(d->argv[1], O_RDONLY);
	r = 0;
	d->map = malloc (d->number_rows * sizeof (char *));
	if (!d->map)
		exit (1);
	ft_initialize_map(d, d->map);
	while (r < d->number_rows)
	{
		d->map[r] = NULL;
		str = ft_get_next_line(d->fd);
		if (ft_strlen_n(str) == 0)
			ft_error_messages(5);
		d->map[r] = ft_strdup(str);
		printf("%s\n", d->map[r]);					//--------------------------------		ELIMINAR ESTA LINEA
		r++;
		free(str);
	}
	close(d->fd);
	printf("\nMAPA CREADO CORRECTAMENTE\n\n");			//--------------------------------		ELIMINAR ESTA LINEA
}

void	ft_initialize_data(t_data *d)
{
	d->flag_char = 0;
	d->number_rows = 0;
	d->x_position_player = -1;
	d->y_position_player = -1;
	d->map = NULL;
	d->foundNO = 0;
	d->foundSO = 0;
	d->foundWE = 0;
	d->foundEA = 0;
	d->foundF = 0;
	d->foundC = 0;
	ft_number_rows(d);
	ft_check_characters(d);
	ft_create_map(d);
	ft_check_limits(d);	
}