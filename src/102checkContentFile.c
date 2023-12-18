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

void ft_check_init_row(char *content_without_space, t_data *d)
{
    if (!ft_strncmp(content_without_space, "NO", 2) || !ft_strncmp(content_without_space, "SO", 2)
            || !ft_strncmp(content_without_space, "EA", 2) || !ft_strncmp(content_without_space, "WE", 2))
            {
                if (!ft_strncmp(content_without_space, "NO", 2) && d->foundNO == 0)
                    d->foundNO = 1;
                else if (!ft_strncmp(content_without_space, "NO", 2))
                    ft_error_messages(7);
                else if (!ft_strncmp(content_without_space, "SO", 2) && d->foundNO == 0)
                    d->foundNO = 1;
                else if (!ft_strncmp(content_without_space, "SO", 2))
                    ft_error_messages(7);
                else if (!ft_strncmp(content_without_space, "EA", 2) && d->foundNO == 0)
                    d->foundNO = 1;
                else if (!ft_strncmp(content_without_space, "EA", 2))
                    ft_error_messages(7);
                else if (!ft_strncmp(content_without_space, "WE", 2) && d->foundNO == 0)
                    d->foundNO = 1;
                else if (!ft_strncmp(content_without_space, "WE", 2))
                    ft_error_messages(7);
            }
    else if (!ft_strncmp(content_without_space, "F", 1) 
            || !ft_strncmp(content_without_space, "C", 1))
            {
                if (!ft_strncmp(content_without_space, "F", 1) && d->foundF == 0)
                    d->foundF = 1;
                else if (!ft_strncmp(content_without_space, "F", 1))
                    ft_error_messages(7);
                else if (!ft_strncmp(content_without_space, "C", 1) && d->foundF == 0)
                    d->foundF = 1;
                else if (!ft_strncmp(content_without_space, "C", 1))
                    ft_error_messages(7);                
            }
    else if (d->foundNO == 1 && d->foundSO == 1 && d->foundEA == 1 
            && d->foundWE == 1 && d->foundF == 1 && d->foundC == 1)
            {
                printf("TODO LO QUE VIENE AHORA ES EL MAPA\n");
            }
    else
        ft_error_messages(7);
}

void ft_check_start_row(char *row_n_content, t_data *d)
{
    char    **content_without_space;
    int     r;

    r = 0;
    if (!row_n_content)
        ft_error_messages(7);
    content_without_space = ft_split(row_n_content, ' ');
    while (content_without_space[r])    
    {
        ft_check_init_row(content_without_space[r], d);
        r++;
    }
}

int   ft_check_data_file(t_data *d)
{
    int r;

    r = 0;
    while (d->allContentN[r])
    {
        ft_check_start_row(d->allContentN[r], d);
    }
    return (1);
}

void    ft_check_content_file(t_data *d)
{
    d->allContent = ft_get_all_content(d);
    printf("CONTENIDO allContent -> %s\n", d->allContent);
    d->allContentN = ft_split(d->allContent, '\n');
    printf("\nContenido d->allContentN\n");
    ft_print_matrix(d->allContentN);
    // if (ft_check_data_file(d))
    //     printf("DATOS CORRECTOS EN EL MAPA")
    free(d->allContent);
}