#include "cub3d.h"

int main(int argc, char **argv)
{
	(void) argv;

	if (argc == 2 && ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
	{
		printf("ABRIENDO ARCHIVO...\n");
	}
	else
		printf("ERROR\tDATOS ERRONEOS\n");	
	return (0);
}