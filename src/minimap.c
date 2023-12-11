#include "../include/cub3d.h"

void	minimap(t_map *m)
{
	m->mi_bg = mlx_new_image(m->mlx, 200, 200);
	int i = -1;
	int j = -1;
	// esto es el color de cada pixel
	while (++i < 200)
	{
		j = -1;
		while (++j < 200)
		{
			m->mi_bg->pixels[i * m->mi_bg->width * 4 + j * 4] = 0; 
			m->mi_bg->pixels[i * m->mi_bg->width * 4 + j * 4 + 1] = 0;
			m->mi_bg->pixels[i * m->mi_bg->width * 4 + j * 4 + 2] = 255;
			m->mi_bg->pixels[i * m->mi_bg->width * 4 + j * 4 + 3] = 255;
		}
	}
	// ft_memset(m->mi_bg->pixels, 200, m->mi_bg->width * m->mi_bg->height * BPP);
	mlx_image_to_window(m->mlx, m->mi_bg, 0, 0);
	create_minimap(m);
	//draw_player(m);
}

void	create_minimap(t_map *m)
{
	for (int i = 0; i < 200; i++) 
	{
    	for (int j = 0; j < 200; j++) 
		{
			char elemento = m->d->map[i][j];
			int indice_pixel = i * 200 + j;

			if (elemento == '1') {
				// Muro
				m->mi_bg->pixels[indice_pixel * 4] = (COLOR_MURO >> 16) & 0xFF; // Componente R
				m->mi_bg->pixels[indice_pixel * 4 + 1] = (COLOR_MURO >> 8) & 0xFF; // Componente G
				m->mi_bg->pixels[indice_pixel * 4 + 2] = COLOR_MURO & 0xFF; // Componente B
				m->mi_bg->pixels[indice_pixel * 4 + 3] = 255; // Alfa
			} else if (elemento == '0') {
				// Suelo
				m->mi_bg->pixels[indice_pixel * 4] = (COLOR_SUELO >> 16) & 0xFF;
				m->mi_bg->pixels[indice_pixel * 4 + 1] = (COLOR_SUELO >> 8) & 0xFF;
				m->mi_bg->pixels[indice_pixel * 4 + 2] = COLOR_SUELO & 0xFF;
				m->mi_bg->pixels[indice_pixel * 4 + 3] = 255;
			} else if (elemento == 'N') {
				// Personaje
				m->mi_bg->pixels[indice_pixel * 4] = (COLOR_PERSONAJE >> 16) & 0xFF;
				m->mi_bg->pixels[indice_pixel * 4 + 1] = (COLOR_PERSONAJE >> 8) & 0xFF;
				m->mi_bg->pixels[indice_pixel * 4 + 2] = COLOR_PERSONAJE & 0xFF;
				m->mi_bg->pixels[indice_pixel * 4 + 3] = 255;
			}
		}
    }

/* {
	//dibujar el minimapa
	m->mini = mlx_new_image(m->mlx, 200, 200);
	int dx = 10; //m->mini->width / 4; // tamaño de cada cuadro
    int dy = 10; //m->mini->height / 4; // tamaño de cada cuadro
    int x, y, i, j;

	x = 0;
    while (m->d->map[x])
    {
        y = 0;
        while (m->d->map[x][y])
        {
            i = 0;
            while (i < dx)
            {
                j = 0;
                while (j < dy)
                {
                    if (m->d->map[x][y] == '1')
                    {
                    	ft_memset(m->mini->pixels + ((x * dx + i) * m->mini->width + y * dy + j) * BPP, 0x00FFFFFF, BPP);
                    }
                    else if (m->d->map[x][y] == '0')
                    {
                    	ft_memset(m->mini->pixels + ((x * dx + i) * m->mini->width + y * dy + j) * BPP, 0x00000000, BPP);
                    }
					else if (m->d->map[x][y] == 'E')
					{
						ft_memset(m->mini->pixels + ((x * dx + i) * m->mini->width + y * dy + j) * BPP, 0xFFA07AAA, BPP);
					}
                    j++;
                }
                i++;
            }
            y++;
        }
        x++;
    } */
	/* int dx = 10;
	int dy = 10;
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	while (m->d->map[x])
	{
		x = 0;
		while (m->d->map[x][y] == ' ')
			y++;
		while (m->d->map[x][y] != '\0')
		{
			i = 0;
			while (i < dx)
			{
				j = 0;
				while (j < dy)
				{
					if (m->d->map[x][y] == '1')
					{
						ft_memset(m->mini->pixels + ((x * dy + j)
								* m->mini->width + y * dx + i) * BPP,
							0x00FFFFFF, BPP);
						mlx_put_pixel(m->mini, x * dx + i, y * dy + j, 0x00FFFFFF);
					}
					else if (m->d->map[x][y] == '0')
					{
						ft_memset(m->mini->pixels + ((x * dy + j)
								* m->mini->width + y * dx + i) * BPP,
							0x00000000, BPP);
						mlx_put_pixel(m->mini, x * dx + i, y * dy + j, 0x00000000);
					}
					j++;
				}
				i++;
			}
			y++;
		}
		x++;
	} */
	mlx_image_to_window(m->mlx, m->mini, 0, 0);
}

void	draw_player(t_map *m)
{
	int px;
	int py;
	int dx;
	int dy;
	int i;
	int j;

	px = 0;
	py = 360; //si Height es 720, entonces 100 es 1/7 de la altura
	dx = 10; // Tamaño del "píxel" del jugador
	dy = 10; // Tamaño del "píxel" del jugador
	m->mini = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	i = 0;
	while (i < dx)
	{
		j = 0;
		while (j < dy)
		{
			mlx_put_pixel(m->mini, px + i, py + j, 0xFF0000FF);
				// Dibuja un cuadrado de píxeles
			j++;
		}
		i++;
	}
	if (mlx_image_to_window(m->mlx, m->mini, 0, 0) == -1)
		ft_error_messages(5);
}