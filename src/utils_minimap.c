#include "../include/cub3d.h"

void	number_colums(t_map *m)
{
	int	y;

	y = 0;
	while (m->d->map[0][y])
		y++;
	m->d->number_columns = y;
	printf("%d\n", m->d->number_columns);
}

void	draw_minimap(t_map *m)
{
	int	x;
	int	y;

	number_colums(m);
	m->mini = mlx_new_image(m->mlx, m->d->number_columns * BLOCK_SIZE,
			m->d->number_rows * BLOCK_SIZE);
	x = 0;
	while (x < m->d->number_rows)
	{
		y = 0;
		while (y < m->d->map[x][y])
		{
			if (m->d->map[x][y] == '1')
				draw_block_wall(m, y * BLOCK_SIZE, x * BLOCK_SIZE);
			else if (m->d->map[x][y] == '0')
				draw_block_floor(m, y * BLOCK_SIZE, x * BLOCK_SIZE);
			else if (m->d->map[x][y] == 'N')
				draw_player(m, y * BLOCK_PLAYER, x * BLOCK_PLAYER);
			y++;
		}
		x++;
	}
	if (mlx_image_to_window(m->mlx, m->mini, 0, 0) == -1)
		ft_error_messages(5);
}

void	draw_block_wall(t_map *m, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < BLOCK_SIZE)
	{
		j = 0;
		while (j < BLOCK_SIZE)
		{
			mlx_put_pixel(m->mini, x + i, y + j, 0xFF00FF);
			j++;
		}
		i++;
	}
}

void	draw_block_floor(t_map *m, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < BLOCK_SIZE)
	{
		j = 0;
		while (j < BLOCK_SIZE)
		{
			mlx_put_pixel(m->mini, x + i, y + j, 0x00FFFF);
			j++;
		}
		i++;
	}
}

void	draw_player(t_map *m, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < BLOCK_SIZE)
	{
		j = 0;
		while (j < BLOCK_SIZE)
		{
			mlx_put_pixel(m->mini, x + i, y + j, 0xFF0000FF);
			j++;
		}
		i++;
	}
}