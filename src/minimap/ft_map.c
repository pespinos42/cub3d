#include "cub3d.h"

void ft_map(t_map *m)
{
	int row;
	int colum;

	m->map = mlx_new_image(m->mlx, number_colums(m) * BLOCK_SIZE, m->d->number_rows * BLOCK_SIZE);
	row = 0;
	while (row < m->d->number_rows)
	{
		colum = 0;
		while (colum < m->d->number_columns)
		{
			draw_blocks_map(m, row, colum);
			colum++;
		}
		row++;
	}
	if (mlx_image_to_window(m->mlx, m->map, 0, 0) == -1)
		ft_error_messages(5);
}
void	draw_blocks_map(t_map *m, int row, int colum)
{
	if (m->d->map[row][colum] == '1')
		draw_block_wall_map(m, colum * BLOCK_SIZE, row * BLOCK_SIZE);
	else if (m->d->map[row][colum] == '0')
		draw_block_floor_map(m, colum * BLOCK_SIZE, row * BLOCK_SIZE);
	else if (m->d->map[row][colum] == 'N' || m->d->map[row][colum] == 'S'
		|| m->d->map[row][colum] == 'E' || m->d->map[row][colum] == 'W')
		draw_player_map(m, colum * BLOCK_SIZE, row * BLOCK_SIZE);
}

void	draw_block_wall_map(t_map *m, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < BLOCK_SIZE)
	{
		j = 0;
		while (j < BLOCK_SIZE)
		{
			mlx_put_pixel(m->map, x + i, y + j, 0xFF00FF);
			j++;
		}
		i++;
	}
}

void	draw_block_floor_map(t_map *m, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < BLOCK_SIZE)
	{
		j = 0;
		while (j < BLOCK_SIZE)
		{
			mlx_put_pixel(m->map, x + i, y + j, 0x00FFFF);
			j++;
		}
		i++;
	}
}

void	draw_player_map(t_map *m, int x, int y)
{
	int i;
	int j;

	center_player_block(m, x, y);
	i = 0;
	while (i < BLOCK_SIZE)
	{
		j = 0;
		while (j < BLOCK_SIZE)
		{
			mlx_put_pixel(m->map, x + i, y + j, 0x00FFFFF);
			j++;
		}
		i++;
	}
	//paint_player(m, m->player_x, m->player_y);
}
