#include "cub3d.h"

void    ft_free_all(t_data *d)
{
    int r;

    r = 0;
    while (r < d->number_rows)
    {
        free(d->map[r]);
        r++;
    }
    free (d->map);
}