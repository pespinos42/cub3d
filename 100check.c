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

void	ft_check_characters(t_data *d)
{
	int		r;
	int		i;
	char	*str;

	d->fd = open(d->argv[1], O_RDONLY);
	r = 0;
	i = 0;
	while (r < d->number_rows)
	{
		str = ft_get_next_line(d->fd);
		while (str[i] && str[i] != '\n')
		{
			if (!ft_strchr_int("01NSEW", str[i]))
				ft_error_messages(2);
			i++;
		}
		i = 0;
		r++;
	}
	close(d->fd);
}