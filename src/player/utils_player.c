#include "cub3d.h"

/* void	clear_last_position(t_map *m)
{
	int		i;
	int		j;

	printf("posicion: %f, %f\n", m->p->px, m->p->py);
	printf("dx: %d, dy: %d\n", m->dx, m->dy);
	i = m->p->px - m->dx / 2.0;
	while (i < m->p->px + m->dx / 2.0 + 5)
	{
		j = m->p->py - m->dy / 2.0;
		while (j < m->p->py + m->dy / 2.0 + 5)
		{
			mlx_put_pixel(m->player, i, j, 0x00FFFF);
			j++;
		}
		i++;
	}
} */
void	move_player_map(mlx_key_data_t keydata, t_map *m)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(m, 1, 0);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(m, 1, 0);
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(m, 1, 0);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(m, 1, 0);
}

void	turn_player_map(mlx_key_data_t keydata, t_map *m)
{
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(m, 0, -1);
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(m, 0, 1);
}

void	paint_player(t_map *m, float player_x, float player_y)
{
	int i;
	int j;
	float init_x;
	float init_y;

	init_x = player_x - 2;
	init_y = player_y - 2;

	m->player = mlx_new_image(m->mlx, m->dx, m->dy);
	if (mlx_image_to_window(m->mlx, m->player, init_x, init_y) == -1)
		ft_error_messages(5);
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			mlx_put_pixel(m->player, i, j, 0xFF0000FF);
			j++;
		}
		i++;
	}
	i = 0;
}

void	position_player_pixel(t_player *p)
{
	printf("player px: %f, player py: %f\n", p->px, p->py);
	p->m->player_x = p->px * BLOCK_SIZE / 2;
	p->m->player_y = p->py * BLOCK_SIZE / 2;
	printf("player mx: %f, player my: %f\n", p->m->player_x, p->m->player_y);
}

/* void	ft_print_player(t_map *m)
{
	int	*pointer;
	int	p;

	p = 0;
	pointer = (int *)m->player->pixels;
	while ((unsigned int)p < m->player->width * m->player->height)
		pointer[p++] = 0xFF0000FF;
}
 */