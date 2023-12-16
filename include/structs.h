# include "cub3d.h"

typedef struct s_map	t_map;
typedef struct s_player	t_player;
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
	t_data				*d;
	mlx_t				*mlx;
	mlx_image_t			*mi_bg;
	mlx_image_t			*mini;
	mlx_image_t			*sky_image;
	mlx_image_t			*floor_image;
	mlx_image_t			*bg_image;
	mlx_image_t			*map;
	mlx_image_t			*clear;
	uint32_t			sky_color;
	uint32_t			floor_color;
	const char			*title;
	int					block_player;
	int					block_floor;
	int					block_wall;
	int					start_x;
	int					start_y;
	bool				show_map;
	t_player			*p;
}						t_map;

typedef struct s_player
{
	t_map				*m;
	t_data				*d;
	float				px;
	float				py;
	float				dir_x;
	float				dir_y;
	float				old_dir_x;
	float				old_dir_y;
	float				plane_x;
	float				plane_y;
	float				move_speed;
	float				rot_speed;
	float				angle_rot;
	float				pi;
	int					move;
	int					turn;
}						t_player;

typedef struct s_ray
{
	float				camera_x;
	float				ray_dir_x;
	float				ray_dir_y;
	int					map_x;
	int					map_y;
	float				side_dist_x;
	float				side_dist_y;
	float				delta_dist_x;
	float				delta_dist_y;
	float				perp_wall_dist;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					line_height;
	int					draw_start;
	int					draw_end;
}						t_ray;