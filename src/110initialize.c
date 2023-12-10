 #include "cub3d.h"

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

void	ft_liberate_map(t_data *d)
{
	int	r;

	r = 0;
	while (r < d->number_rows)
	{
		if (d->map[r] != NULL)
			free(d->map[r]);
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
	while (r < d->number_rows)
	{
		d->map[r] = NULL;
		str = ft_get_next_line(d->fd);
		d->map[r] = ft_strdup(str);
		printf("%s\n", d->map[r]);					//--------------------------------		ELIMINAR ESTA LINEA
		r++;
		free(str);
	}
	close(d->fd);
	printf("\nMAPA CREADO CORRECTAMENTE\n\n");			//--------------------------------		ELIMINAR ESTA LINEA
}
