#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <fcntl.h>  //PARA OPERACIONES DE FICHEROS OPEN...
# include <stddef.h> //PARA DEFINIR NULL
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> //PARA READ

typedef struct s_list
{
    struct s_list   *next;
    char            *content;
}   t_list;

typedef struct s_atoi_data
{
	int	result;
	int	sign;
	int	s;
}	t_atoi_data;

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**map;
	char	**map_flood_fill;
	char	**allContentN;
	char	*allContent;
	int		number_rows;
	int		number_columns;
	int		fd;
	int		flag_char;
	int		x_position_player;
	int		y_position_player;
	int		foundNO;
	char	*pathNO;
	int		foundSO;
	char	*pathSO;
	int		foundWE;
	char	*pathWE;
	int		foundEA;
	char	*pathEA;
	int		foundF;
	char	*pathF;
	int		foundC;
	char	*pathC;
	int		foundMap;
	int		fR;
	int		fG;
	int		fB;
	int		cR;
	int		cG;
	int		cB;
	t_list	*row_list;
}			t_data;

typedef struct s_split_data
{
	char	**result;
	int		p;
	int		w;
	int		start;
}	t_split_data;

// MAIN
void		ft_leaks(void);

// 000LIBFT1
int			ft_strlen(char *str);
char		*ft_strnstr(char *b, char *l, size_t len);
char		*ft_strdup(char *src);
int			ft_strncmp(const char *lsh, const char *rhs, int count);
int			ft_atoi(const char *str);

// 001SPLIT
char		**ft_split(char *s, char c);

// 002LISTS
t_list		*ft_lstnew(char *content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstprint(t_list *lst);

// 100CHECK
int			ft_check_parameters(t_data *d);
void		ft_check_characters(t_data *d);
int			ft_allow_chars(char *s, t_data *d);

// 101-1CHECKLIMITS
void		ft_duplicate_map(t_data *d);
void		ft_flood_fill(int x, int y, t_data *d);
void		ft_print_map(t_data *d);
void		ft_locate_player(t_data *d);
int			ft_check_inner_walls(t_data *d);

// 101-2CHECKLIMITS
int     	ft_check_around(t_data *d, int x, int y);
int			ft_check_outer_walls(t_data *d);
void		ft_compare_maps(t_data *d);
void    	ft_check_outer_chars(t_data *d);
void		ft_check_limits(t_data *d);

// 102CHECKCONTENTFILE
void    	ft_print_matrix(char **matrix);
char		*ft_my_strjoin(char **str1, char **str2);
char    	*ft_get_all_content(t_data *d);
void 		ft_check_init_row(char *content_without_space, char *path, t_data *d);
void 		ft_check_start_row(char *row_n_content, t_data *d);
void    	ft_add_row_list(t_data *d, char *str);
int   		ft_check_data_file(t_data *d);
char		**ft_create_map(t_data *d);
void		ft_check_content_file(t_data *d);

// 110INITIALIZE
void		ft_number_rows(t_data *d);
void		ft_initialize_map(t_data *d, char **map);
void		ft_initialize_data(t_data *d);

// 120ERRORMESSAGES
void		ft_error_messages(int message);

// 200GNL
char		*ft_join_free(char *buffer, char *str);
char		*ft_get_next_line(int fd);

// 210GNLUTILS
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s, unsigned int start, size_t len);
int			ft_strlen_n(const char *s);
char		*ft_strchr(const char *s, int c);

// 999FREE
void		ft_free_all(t_data *d);
void    	ft_free_matrix(char **matrix);

#endif