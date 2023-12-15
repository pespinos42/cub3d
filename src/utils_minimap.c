#include "../include/cub3d.h"

int	number_colums(t_map *m)
{
	int	y;

	y = 0;
	while (m->d->map[0][y])
		y++;
	m->d->number_columns = y;
	return (y);
}

void	draw_minimap(t_map *m)
{
	int	x;
	int	y;

	centre_player(m);
	m->mini = mlx_new_image(m->mlx, WIDTH_MINIMAP, HEIGHT_MINIMAP);
	x = m->start_x;
	while (x < m->start_x + WIDTH_MINIMAP / BLOCK_SIZE && x < m->d->number_rows)
	{
		y = m->start_y;
		while (y < m->start_y + HEIGHT_MINIMAP / BLOCK_SIZE
			&& y < number_colums(m))
		{
			draw_blocks(m, x, y);
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