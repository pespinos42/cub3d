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

void    ft_print_control_data(t_data *d)
{
    printf("FOUNDNO -> %i\n", d->foundNO);
    printf("FOUNDSO -> %i\n", d->foundSO);
    printf("FOUNDEA -> %i\n", d->foundEA);
    printf("FOUNDWE -> %i\n", d->foundWE);
    printf("FOUNDF  -> %i\n", d->foundF);
    printf("FOUNDC  -> %i\n", d->foundC);
    printf("FOUNDMAP -> %i\n", d->foundMap);
}

void ft_check_init_row(char *content_without_space, t_data *d)
{
    ft_print_control_data(d);
    if (!ft_strncmp(content_without_space, "NO", 2) || !ft_strncmp(content_without_space, "SO", 2)
            || !ft_strncmp(content_without_space, "EA", 2) || !ft_strncmp(content_without_space, "WE", 2))
            {
                if (!ft_strncmp(content_without_space, "NO", 2) && d->foundNO == 0)
                {
                    printf("NO Y FOUNDNO = 0\n");
                    d->foundNO = 1;
                }
                else if (!ft_strncmp(content_without_space, "NO", 2))
                {
                    printf("NO Y FOUNDNO = 1\n");
                    ft_error_messages(7);
                }
                else if (!ft_strncmp(content_without_space, "SO", 2) && d->foundSO == 0)
                {
                    printf("SO Y FOUNDSO = 0\n");
                    d->foundSO = 1;
                }
                else if (!ft_strncmp(content_without_space, "SO", 2))
                {
                    printf("SO Y FOUNDSO = 1\n");
                    ft_error_messages(7);
                }
                else if (!ft_strncmp(content_without_space, "EA", 2) && d->foundEA == 0)
                {
                    printf("EA Y FOUNDEA = 1\n");
                    d->foundEA = 1;
                }
                else if (!ft_strncmp(content_without_space, "EA", 2))
                {
                    printf("EA Y FOUNDEA = 0\n");
                    ft_error_messages(7);
                }
                else if (!ft_strncmp(content_without_space, "WE", 2) && d->foundWE == 0)
                {
                    printf("WE Y FOUNDWE = 0\n");
                    d->foundWE = 1;
                }
                else if (!ft_strncmp(content_without_space, "WE", 2))
                {
                    printf("WE Y FOUNDWE = 1\n");
                    ft_error_messages(7);
                }
            }
    else if (!ft_strncmp(content_without_space, "F", 1) 
            || !ft_strncmp(content_without_space, "C", 1))
            {
                if (!ft_strncmp(content_without_space, "F", 1) && d->foundF == 0)
                {
                    printf("F Y FOUNDF = 0\n");
                    d->foundF = 1;
                }
                else if (!ft_strncmp(content_without_space, "F", 1))
                {
                    printf("F Y FOUNDF = 1\n");
                    ft_error_messages(7);
                }
                else if (!ft_strncmp(content_without_space, "C", 1) && d->foundC == 0)
                {
                    printf("C Y FOUNDC = 0\n");
                    d->foundC = 1;
                }
                else if (!ft_strncmp(content_without_space, "C", 1))
                {
                    printf("C Y FOUNDC = 1\n");
                    ft_error_messages(7);                
                }
            }
    else if (d->foundNO == 1 && d->foundSO == 1 && d->foundEA == 1 
            && d->foundWE == 1 && d->foundF == 1 && d->foundC == 1)
            {
                printf("TODO LO QUE VIENE AHORA ES EL MAPA\n");
                d->foundMap = 1;
            }
    else
        ft_error_messages(7);
    printf("FINAL DEL COMPROBADOR\n");
}

void ft_check_start_row(char *row_n_content, t_data *d)
{
    char    **content_without_space;

    if (!row_n_content)
        ft_error_messages(7);
    content_without_space = ft_split(row_n_content, ' ');
    ft_check_init_row(content_without_space[0], d);
    ft_free_matrix(content_without_space);
}

int   ft_check_data_file(t_data *d)
{
    int r;

    r = 0;
    while (d->allContentN[r])
    {
        printf("COMPROBANDO FILA -> %i\n", r);
        ft_check_start_row(d->allContentN[r], d);
        r++;
    }
    if (d->foundNO == 1 && d->foundSO == 1 && d->foundEA == 1
            && d->foundWE == 1 && d->foundF == 1 && d->foundC == 1
            && d->foundMap == 1)
                return (1);
    else
    {
        ft_error_messages(7);
        return (0);
    }
}

void    ft_check_content_file(t_data *d)
{
    d->allContent = ft_get_all_content(d);
    printf("CONTENIDO allContent -> %s\n", d->allContent);
    d->allContentN = ft_split(d->allContent, '\n');
    printf("\nContenido d->allContentN\n");
    ft_print_matrix(d->allContentN);
    if (ft_check_data_file(d))
        printf("DATOS CORRECTOS EN EL MAPA");
    free(d->allContent);
}