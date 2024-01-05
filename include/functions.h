#include "cub3d.h"

// MAIN
void	ft_leaks(void);

// 000LIBFT1
int		ft_strlen(char *str);
char	*ft_strnstr(char *b, char *l, size_t len);
char	*ft_strdup(char *src);

// 100CHECK
int		ft_check_parameters(t_data *d);
void	ft_check_characters(t_data *d);
int		ft_allow_chars(char *s, t_data *d);

// 101CHECKLIMITS
void	ft_duplicate_map(t_data *d);
void	ft_flood_fill(int x, int y, t_data *d);
void	ft_print_map(t_data *d);
void	ft_locate_player(t_data *d);
int		ft_check_inner_walls(t_data *d);
int		ft_check_outer_walls(t_data *d);
void	ft_compare_maps(t_data *d);
void	ft_check_limits(t_data *d);

// 110INITIALIZE
void	ft_number_rows(t_data *d);
void	ft_liberate_map(t_data *d);
void	ft_create_map(t_data *d);

// 120ERRORMESSAGES
void	ft_error_messages(int message);

// 200GNL
char	*ft_get_next_line(int fd);

// 210GNLUTILS
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strlen_n(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);

// 999FREE
void	ft_free_all(t_data *d);

// PRUEBA
void	ft_duplicate_map(t_data *d);
void	ft_flood_fill(int x, int y, t_data *d);
void	ft_print_map(t_data *d);
void	ft_locate_player(t_data *d);
void	ft_check_limits(t_data *d);

// UTILS_STRUCTS
void	init_struct_data_map(t_data *d, t_map *m);
void	ft_initialize_data(t_data *d);
void	ft_initialize_map(t_map *m);

// UTILS_STRUCTS2
void	ft_initialize_player(t_map *m, t_player *p);
void	ft_initialize_ray(t_map *m, t_player *p, t_ray *r);
void	ft_bresenham(t_map *m, t_bresenham *b);

// MAIN_GAME
int32_t	ft_main_game(t_map *map);
void	hook(void *param);
void	key_hook(mlx_key_data_t keydata, void *param);
void	ft_paint_map(t_map *m);

// FT_PLAYER
void	move_player(t_map *m, int move, int turn);
void	draw_direction_line(t_map *m, t_bresenham *b);
//void	ft_print_player(t_map *m);

// UTILS_PLAYER
//void	clear_last_position(t_map *m);
void	paint_player(t_map *m, float player_x, float player_y);
void	move_player_map(mlx_key_data_t keydata, t_map *m);
void	turn_player_map(mlx_key_data_t keydata, t_map *m);

// MINIMAP
void	minimap(t_map *m);
void	centre_player(t_map *m);
void	draw_blocks(t_map *m, int x, int y);
void	center_player_block(t_map *m, int x, int y);

// FT_MAP
void	ft_map(t_map *m);
void	draw_blocks_map(t_map *m, int x, int y);
void	draw_block_wall_map(t_map *m, int x, int y);
void	draw_block_floor_map(t_map *m, int x, int y);
void	draw_player_map(t_map *m, int row, int colum);

// UTILS_MAP
int		number_colums(t_map *m);
void	draw_minimap(t_map *m);
void	draw_block_wall(t_map *m, int x, int y);
void	draw_block_floor(t_map *m, int x, int y);
void	draw_player(t_map *m, int x, int y);


