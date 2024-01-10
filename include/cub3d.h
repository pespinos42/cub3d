#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <string.h>
# include <stddef.h>  //PARA DEFINIR NULL
# include "../MLX42/include/MLX42/MLX42.h"
# include "structs.h"
# include "functions.h"
# include "raycasting.h"
# include <stdio.h>
# include <fcntl.h> //PARA OPERACIONES DE FICHEROS OPEN...
# include <float.h> //PARA FLT_MAX
# include <math.h>
# include <stdbool.h> //PARA BOOLEANOS
# include <stdlib.h>
# include <unistd.h> //PARA READ

/* Define window size */
# define WIDTH 1280
# define HEIGHT 720
# define WIDTH_MINIMAP 200
# define HEIGHT_MINIMAP 200
# define BLOCK_SIZE 35
# define INFINITE	1e30

#endif