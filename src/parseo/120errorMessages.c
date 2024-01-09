#include "cub3d.h"

void	ft_error_messages(int message)
{
	printf("ERROR\n");
	if (message == 1)
		printf("SE HA PRODUCIDO UN ERROR EN LA COMPROBACION PREVIA DEL FICHERO\n\n");
	else if (message == 2)
		printf("SE HAN ENCONTRADO CARACTERES INVALIDOS EN EL MAPA\n\n");
	else if (message == 3)
		printf("MUROS NO CERRADOS\n\n");
	else if (message == 4)
		printf("NO HAY JUGADOR\n\n");
	exit(1);
}