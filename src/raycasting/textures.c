#include "cub3d.h"

void	load_textures(t_ray *r)
{
	r->img_ea = mlx_load_png("./textures/EA/tex5.png");
	r->img_no = mlx_load_png("./textures/NO/tex3.png");
	r->img_so = mlx_load_png("./textures/S0/tex1.png");
	r->img_we = mlx_load_png("./textures/WE/tex6.png");
	r->text_ea = mlx_texture_to_image(r->m->mlx, r->img_ea);
	r->text_no = mlx_texture_to_image(r->m->mlx, r->img_no);
	r->text_so = mlx_texture_to_image(r->m->mlx, r->img_so);
	r->text_we = mlx_texture_to_image(r->m->mlx, r->img_we);
	r->texs[0] = r->text_no;
    r->texs[1] = r->text_so;
    r->texs[2] = r->text_we;
    r->texs[3] = r->text_ea;
	clear_texture(r);
}

void	clear_texture(t_ray *r)
{
	mlx_delete_texture(r->img_ea);
	mlx_delete_texture(r->img_no);
	mlx_delete_texture(r->img_so);
	mlx_delete_texture(r->img_we);
}

/**
 * @brief Calcular la coordenada de la textura
 *Si side = 0, ha colisionado con una pared en el eje x, direccion norte o sur
 *Si side = 1, ha colisionado con una pared en el eje y, direccion este u oeste
*/

void	coordinate_texture(t_ray *r)
{
	if (r->side == 0)
		r->text_coord = r->p->py + r->perp_wall_dist * r->ray_dir_y;
	else
		r->text_coord = r->p->px + r->perp_wall_dist * r->ray_dir_x;
	r->text_coord -= floor((r->text_coord));
}

/**
 * @brief Verifica en que lado ha colisionado con la pared
 * Si side = 0, ha colisionado con una pared en el eje x, direccion norte
 * Si side = 1, ha colisionado con una pared en el eje y, direccion este
 * Si side = 2, ha colisionado con una pared en el eje x, direccion oeste
 * Si side = 3, ha colisionado con una pared en el eje x, direccion este
*/

void	check_side(t_ray *r)
{
	if (r->side == 0 && r->ray_dir_x > 0)
		r->side = 3;
	else if (r->side == 0 && r->ray_dir_x < 0)
		r->side = 2;
	else if (r->side == 1 && r->ray_dir_y > 0)
		r->side = 1;
	else
		r->side = 0;
}