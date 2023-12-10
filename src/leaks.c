#include "../include/cub3d.h"

void	imprimir_variables(t_map *m, t_player *p)
{
	(void)m;
	printf("posicion jugador X = %f\n", p->px);
	printf("posicion jugador Y = %f\n", p->py);
	printf("valor de pi = %f\n", p->pi);
	printf("valor rot_speed = %f\n", p->rot_speed);
}
void	ft_leaks(void)
{
	system("leaks -q cub3d");
}