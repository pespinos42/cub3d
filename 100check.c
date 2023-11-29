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
	char	*str;

	d->fd = open(d->argv[1], O_RDONLY);
	r = 0;
	while (r < d->number_rows)
	{
		str = ft_get_next_line(d->fd);
		if (!ft_allow_chars(str, d))
			ft_error_messages(2);
		r++;
	}
	close(d->fd);
}