#include "../include/cub3d.h"

void    ft_free_matrix(char **matrix)
{
    int x;

    x = 0;
    while (matrix[x])
    {
        free (matrix[x]);
        x++;
    }
    free (matrix);
}

void    ft_free_all(t_data *d)
{
    // int r;

    // r = 0;
    // while (r < d->number_rows)
    // {
    //     if (d->map[r])
    //         free(d->map[r]);
    //     if (d->map_flood_fill[r])
    //         free(d->map_flood_fill[r]);
    //     r++;
    // }
    // if (d->map)
    //     free (d->map);
    // if (d->map_flood_fill)
    //     free (d->map_flood_fill);
    ft_free_matrix(d->allContentN);
    free (d->pathNO);
    free (d->pathSO);
    free (d->pathEA);
    free (d->pathWE);
}