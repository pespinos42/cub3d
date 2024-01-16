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
	mlx_delete_texture(r->img_ea);
	mlx_delete_texture(r->img_no);
	mlx_delete_texture(r->img_so);
	mlx_delete_texture(r->img_we);
}

/**
 * @brief Verifica en que lado ha colisionado con la pared
 * Si tex_num = 0, ha colisionado con una pared en el eje x, direccion norte
 * Si tex_num = 1, ha colisionado con una pared en el eje y, direccion sur
 * Si tex_num = 2, ha colisionado con una pared en el eje x, direccion oeste
 * Si tex_num = 3, ha colisionado con una pared en el eje x, direccion este
 */

void	wall_face(t_ray *r)
{
	if (r->side == 0)
	{
		if (r->ray_dir_x > 0)
			r->side = 3;
		else
			r->side = 2;
	}
	else
	{
		if (r->ray_dir_y > 0)
			r->side = 1;
		else
			r->side = 0;
	}
	if (r->side == 0)
		printf("choca en la cara norte\n");
	if (r->side == 1)
		printf("choca en la cara sur\n");
	if (r->side == 2)
		printf("choca en la cara oeste\n");
	if (r->side == 3)
		printf("choca en la cara este\n");
}

/**
 * @brief Calcular la coordenada de la textura
 *Si side = 0, ha colisionado con una pared en el eje x, direccion norte o sur
 *Si side = 1, ha colisionado con una pared en el eje y, direccion este u oeste
 */

void	coordinate_wall_x(t_ray *r)
{
	if (r->side == 0)
		r->wall_x = r->p->py + r->perp_wall_dist * r->ray_dir_y;
	else
		r->wall_x = r->p->px + r->perp_wall_dist * r->ray_dir_x;
	r->wall_x -= floor((r->wall_x));
	r->tex_x = (int)(r->wall_x * (float)TEXWIDTH);
	printf("wall_x: %f\n", r->wall_x);

	printf("tex_x: %d\n", r->tex_x);
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
		r->tex_x = TEXWIDTH - r->tex_x - 1;
	if (r->side == 1 && r->ray_dir_y < 0)
		r->tex_x = TEXWIDTH - r->tex_x - 1;
}

/**
 * @brief Calcular el pixel mas alto y mas bajo para dibujar la pared
 * Calcula cuanto avanzar en la textura
 * Calcula la posicion inicial de la textura desde donde empezar a dibujar
 */

void	init_position_texture(t_ray *r)
{
	r->step = 1.0 * TEXHEIGHT / r->line_height;
	r->tpos = (r->draw_start - HEIGHT / 2 + r->line_height / 2) * r->step;
}
