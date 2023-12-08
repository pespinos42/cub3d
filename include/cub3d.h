#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h> //PARA OPERACIONES DE FICHEROS OPEN...
# include <math.h>
# include <stdbool.h> //PARA BOOLEANOS
# include <stddef.h>  //PARA DEFINIR NULL
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h> //PARA READ
# include <float.h> //PARA FLT_MAX

/* Define window size */
# define WIDTH 1280
# define HEIGHT 720
# define BPP sizeof(int32_t)

typedef struct s_map	t_map;
typedef struct s_data
{
	int					argc;
	char				**argv;
	char				**map;
	char				**map_flood_fill;
	int					number_rows;
	int					number_columns;
	int					fd;
	int					flag_char;
	int					x_position_player;
	int					y_position_player;
}						t_data;

typedef struct s_map
{
	t_data				*data;
	mlx_t				*mlx;
	mlx_image_t			*img;
	mlx_image_t			*sky_image;
	mlx_image_t			*floor_image;
	mlx_image_t			*bg_image;
	uint32_t			sky_color;
	uint32_t			floor_color;
	const char			*title;
	int					px;
	int					py;
}						t_map;

// MAIN
void					ft_leaks(void);

// 000LIBFT1
int						ft_strlen(char *str);
char					*ft_strnstr(char *b, char *l, size_t len);
char					*ft_strdup(char *src);

// 100CHECK
int						ft_check_parameters(t_data *d);
void					ft_check_characters(t_data *d);
int						ft_allow_chars(char *s, t_data *d);

// 101CHECKLIMITS
void					ft_duplicate_map(t_data *d);
void					ft_flood_fill(int x, int y, t_data *d);
void					ft_print_map(t_data *d);
void					ft_locate_player(t_data *d);
int						ft_check_inner_walls(t_data *d);
int						ft_check_outer_walls(t_data *d);
void					ft_compare_maps(t_data *d);
void					ft_check_limits(t_data *d);

// 110INITIALIZE
void					ft_initialize_data(t_data *d);
void					ft_initialize_map(t_data *d, t_map *m);

// 120ERRORMESSAGES
void					ft_error_messages(int message);

// 200GNL
char					*ft_get_next_line(int fd);

// 210GNLUTILS
char					*ft_strjoin(char *s1, char *s2);
char					*ft_substr(char *s, unsigned int start, size_t len);
int						ft_strlen_n(const char *s);
char					*ft_strchr(const char *s, int c);

// 999FREE
void					ft_free_all(t_data *d);

// PRUEBA
void					ft_duplicate_map(t_data *d);
void					ft_flood_fill(int x, int y, t_data *d);
void					ft_print_map(t_data *d);
void					ft_locate_player(t_data *d);
void					ft_check_limits(t_data *d);

// MAIN_GAME
int32_t					ft_main_game(t_map *map);

// BACKGROUND
void					background(t_map *m);
void					map_color_background(t_map *map);


// MINIMAP
void					create_minimap(t_map *map);
void					draw_player(t_map *m);

#endif