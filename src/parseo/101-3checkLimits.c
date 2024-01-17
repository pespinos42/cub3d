#include "../include/cub3d.h"

void	ft_check_limits(t_data *d)
{
	ft_check_content_file(d);
	ft_duplicate_map(d);
	ft_locate_player(d);
	ft_flood_fill(d->x_position_player, d->y_position_player, d);
	ft_fill_islands(d);
	ft_compare_maps(d);
}
