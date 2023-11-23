#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h> //PARA DEFINIR NULL
# include <fcntl.h> //PARA OPERACIONES DE FICHEROS OPEN...
# include <unistd.h> //PARA READ

typedef struct s_data
{
	int		argc;
	char	**argv;
	char    **map;
	int     number_rows;
	int     number_columns;
	int		fd;
}   t_data;

//LIBFT1
int     ft_strlen(char *str);
char    *ft_strnstr(char *b, char *l, size_t len);
//100CHECK
int		ft_check_parameters(t_data *d);
//110INITIALIZE
void	ft_initialize_data(t_data *d);
//120ERRORMESSAGES
void	ft_error_messages(int message);
//200GNL
char	*ft_get_next_line(int fd);
//210GNLUTILS
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
int		ft_strlen_n(const char *s);

#endif