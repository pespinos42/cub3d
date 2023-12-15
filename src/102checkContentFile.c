#include "../include/cub3d.h"

void    ft_print_matrix(char **matrix, int rows)
{
    int x;

    x = 0;
    while (x < rows)
    {
       printf("%s\n", matrix[x]);
       x++;
    }
    printf("\n");
}

char    *ft_get_all_content(t_data *d)
{
    char    *allStr;
    char    *newStr;

    d->fd = open(d->argv[1], O_RDONLY);
    newStr = ft_get_next_line(d->fd);
    while (newStr)
    {
        allStr = ft_strjoin(allStr, newStr); //esta funcion tiene leaks
        free (newStr);
        newStr = ft_get_next_line(d->fd);
    }
    return (allStr);
}

void    ft_check_content_file(t_data *d)
{
    (void) d;
    char *allStr;

    allStr = ft_get_all_content(d);
    printf("CONTENIDO ALLSTR -> %s\n", allStr);
}