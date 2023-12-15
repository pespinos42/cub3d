#include "../include/cub3d.h"

void    ft_print_matrix(char **matrix)
{
    int x;

    x = 0;
    while (matrix[x])
    {
       printf("%s\n", matrix[x]);
       x++;
    }
    printf("\n");
}

char	*ft_my_strjoin(char **str1, char **str2)
{
	char	*str;
    char    *s1;
    char    *s2;
	int		p;
    int     q;

    if (*str1)
    {
        p = 0;
        q = 0;
        str = malloc ((ft_strlen(*str1) + ft_strlen(*str2) + 2) * sizeof (*str));
        if (!str)
        {
            free (str);
            return (NULL);
        }
        s1 = ft_strdup(*str1);
        s2 = ft_strdup(*str2);
        while (s1[p])
        {
            str[p] = s1[p];
            p++;
        }
        while (s2[q])
        {
            str[p + q] = s2[q];
            q++;
        }
        str[p + q] = '\n';
        str[p + q + 1] = '\0';
        free (s1);
        free (s2);
        if (*str1)
            free (*str1);
        return (str);
    }
    else
        return (ft_strdup(*str2));
}

char    *ft_get_all_content(t_data *d)
{
    char    *allStr;
    char    *newStr;
    int     r;

    d->fd = open(d->argv[1], O_RDONLY);
    newStr = ft_get_next_line(d->fd);
    r = 0;
    while (newStr)
    {
        if (r == 0)
            allStr = NULL;
        allStr = ft_my_strjoin(&allStr, &newStr);
        free (newStr);
        newStr = ft_get_next_line(d->fd);
        r++;
    }
    return (allStr);
}

void    ft_check_content_file(t_data *d)
{
    d->allContent = ft_get_all_content(d);
    printf("CONTENIDO allContent -> %s\n", d->allContent);
    d->allContentN = ft_split(d->allContent, '\n');
    printf("\nContenido d->allContentN\n");
    ft_print_matrix(d->allContentN);
    

    free(d->allContent);
}