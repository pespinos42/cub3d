 #include "cub3d.h"

char	*ft_strdup(char *src)
{
	char	*str;
	int		pos;

	pos = 0;
	str = NULL;
	str = (char *) malloc ((ft_strlen_n(src) + 1) * sizeof(char));
	if (str)
	{
		while (src[pos] && src[pos] != '\n')
		{
			str[pos] = src[pos];
			pos++;
		}
		str[pos] = '\0';
	}
	else
	{
		free(str);
		return (NULL);
	}
	return (str);
}

void	ft_number_rows(t_data *d)
{
	int	rows;
	char	*str;

	d->fd = open(d->argv[1], O_RDONLY);
	rows = 0;
	str = ft_get_next_line(d->fd);
	while (str != NULL)
	{
		//printf("STR -> %sLEN -> %i\n", str, ft_strlen(str));
		rows++;
		str = ft_get_next_line(d->fd);
	}
	d->number_rows = rows;
	//printf("NUMERO DE FILAS -> %i\n", d->number_rows);
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
		printf("%s\n", d->map[r]);
		r++;
	}
	close(d->fd);
	printf("MAPA CREADO CORRECTAMENTE\n");
}

void	ft_initialize_data(t_data *d)
{
	d->map = NULL;
	ft_number_rows(d);
	ft_check_characters(d);
	ft_create_map(d);
}