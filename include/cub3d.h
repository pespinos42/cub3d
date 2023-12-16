#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h> //PARA OPERACIONES DE FICHEROS OPEN...
# include <float.h> //PARA FLT_MAX
# include <math.h>
# include <stdbool.h> //PARA BOOLEANOS
# include <stddef.h>  //PARA DEFINIR NULL
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h> //PARA READ
# include "structs.h"
# include "functions.h"

/* Define window size */
# define WIDTH 1280
# define HEIGHT 720
# define WIDTH_MINIMAP 200
# define HEIGHT_MINIMAP 200
# define BLOCK_SIZE 25
# define PLAYER_SIZE 0.5
# define COLOR_MURO 0xFF00FF      // Rojo intenso
# define COLOR_SUELO 0x00FF00     // Verde intenso
# define COLOR_PERSONAJE 0x0000FF // Azul intenso

#endif