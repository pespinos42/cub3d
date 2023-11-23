#include "cub3d.h"

void	ft_number_rows(t_data *d)
{
	int	rows;
	char	*str;

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

	r = 0;
	d->map = malloc (d->number_rows * sizeof (char *));
	if (!d->map)
		exit (1);
	while (r < d->number_rows)
	{
		d->map[r] = NULL;
		str = ft_get_next_line(d->fd);
		if (r < d->number_rows -1)
			d->map[r] = malloc (ft_strlen(str) * sizeof (char));
		else
			d->map[r] = malloc ((ft_strlen(str) + 1) * sizeof (char));
		if (!d->map[r])
		{
			ft_liberate_map(d);
			exit(1);
		}
		r++;
	}
	close(d->fd);
}

void	ft_print_map(t_data *d)
{
	printf("IMPRIMIENDO MAPA...\n");
	
	printf("%c\n", d->map[0][0]);
}

void	ft_fill_map(t_data *d)
{
	int		r;
	int		i;
	char	*str;

	r = 0;
	i = 0;
	str = ft_get_next_line(d->fd);
	while(r < d->number_rows)
	{
		printf("CADENA A COPIAR -> %s", str);
		while (str[i] && str[i] != '\n')
		{
			d->map[r][i] = str[i];
			printf("[%c]", d->map[r][i]);
			i++;
		}
		i = 0;
		printf("\n");
		d->map[r][i] = '\0';
		str = ft_get_next_line(d->fd);
		r++;
	}
	close (d->fd);
}

void	ft_initialize_data(t_data *d)
{
	d->map = NULL;
	d->fd = open(d->argv[1], O_RDONLY);
	ft_number_rows(d);
	d->fd = open(d->argv[1], O_RDONLY);
	ft_create_map(d);
	d->fd = open(d->argv[1], O_RDONLY);
	ft_fill_map(d);
	ft_print_map(d);
}