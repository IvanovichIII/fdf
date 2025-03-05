/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:44:21 by igomez-s          #+#    #+#             */
/*   Updated: 2025/03/04 22:49:49 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_content(t_fdf *fdf)
{
	mlx_delete_image(fdf->mlx, fdf->g_img);
	fdf->g_img = mlx_new_image(fdf->mlx, fdf->width + 1, fdf->height + 1);
	mlx_image_to_window(fdf->mlx, fdf->g_img, 0, 0);
}

void	check_keypress(mlx_key_data_t key, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(fdf->mlx);
	if (key.key == MLX_KEY_UP && key.action == MLX_PRESS)
	{
		fdf->ang -= 0.1;
		clear_content(fdf);
	}
	if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
	{
		fdf->ang += 0.1;
		clear_content(fdf);
	}
}

int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void print_map(t_fdf *fdf)
{
	int i = 0;
	while (i < fdf->fil)
	{
		int j = 0;
		while (j < fdf->col)
		{
			ft_printf("%d ", fdf->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void put_pix(t_fdf *fdf, int x, int y, int color)
{
	mlx_put_pixel(fdf->g_img, x, y, color);
}

float maxF(float a, float b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

float fmodule(float i)
{
	if (i < 0)
	{
		return -i;
	}
	else
	{
		return i;
	}
}

void bresenham(t_fdf *fdf, int *puntos, int color)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err; 

	dx = abs(puntos[2] - puntos[0]);
	dy = abs(puntos[3] - puntos[1]);
	sx = (puntos[0] < puntos[2]) ? 1 : -1;
	sy = (puntos[1] < puntos[3]) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		put_pix(fdf, puntos[0], puntos[1], color);
		if (puntos[0] == puntos[2] && puntos[1] == puntos[3])
			break;
		int e2 = err * 2;
		if (e2 > -dy)
		{
			err -= dy;
			puntos[0] += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			puntos[1] += sy;
		}
	}
}

/*void dale_duro(void *param)
{
	int x;
	int y;
	t_fdf *fdf;
	float puntos[4];

	fdf = param;
	y = 0;
	//print_map(fdf);
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			puntos[0] = y;
			puntos[1] = x;
			puntos[2] = y + 1;
			puntos[3] = x;
			if (x < fdf->fil)
			{
				//ft_printf("%d", fdf->map[x][y]);
				bresenham(fdf, puntos, get_rgba(fdf->map[x][y] * 10 + 10, 0, fdf->map[x][y] * 3, 255));
			}
			//ft_printf("\n");
			puntos[0] = y;
			puntos[1] = x;
			puntos[2] = y;
			puntos[3] = x + 1;
			if (y < fdf->col - 1)
			{
				//ft_printf("%d", fdf->map[x][y]);
				bresenham(fdf, puntos, get_rgba(255, 0, 0, 255));
			}
			x++;
		}
		y++;
	}
}*/

void dale_duro2(t_fdf *fdf, int puntos[4], int i, int j)
{
	puntos[0] = j * fdf->zoom;
	puntos[1] = i * fdf->zoom;
	puntos[2] = j * fdf->zoom + fdf->zoom;
	puntos[3] = i * fdf->zoom;
	puntos[0] = (puntos[0] - puntos[1]) * cos(fdf->ang);
	puntos[1] = (puntos[0] + puntos[1]) * sin(fdf->ang) - fdf->map[i][j];
	puntos[2] = (puntos[2] - puntos[3]) * cos(fdf->ang);
	puntos[3] = (puntos[2] + puntos[3]) * sin(fdf->ang) - fdf->map[i][j + 1];
	puntos[0] += fdf->width / 2;
	puntos[1] += fdf->width / 5;
	puntos[2] += fdf->width / 2;
	puntos[3] += fdf->width / 5;
	if (fdf->map[i][j] != 0)
		bresenham(fdf, puntos, get_rgba(0, fdf->map[i][j] * 10 + 10, fdf->map[i][j] * 3, 255));
	else
		bresenham(fdf, puntos, get_rgba(0, 0, 0, 255));
}

void dale_duro3(t_fdf *fdf, int puntos[4], int i, int j)
{
	puntos[0] = j * fdf->zoom;
	puntos[1] = i * fdf->zoom;
	puntos[2] = j * fdf->zoom;
	puntos[3] = i * fdf->zoom + fdf->zoom;
	puntos[0] = (puntos[0] - puntos[1]) * cos(fdf->ang);
	puntos[1] = (puntos[0] + puntos[1]) * sin(fdf->ang) - fdf->map[i][j];
	puntos[2] = (puntos[2] - puntos[3]) * cos(fdf->ang);
	puntos[3] = (puntos[2] + puntos[3]) * sin(fdf->ang) - fdf->map[i + 1][j];
	puntos[0] += fdf->width / 2;
	puntos[1] += fdf->width / 5;
	puntos[2] += fdf->width / 2;
	puntos[3] += fdf->width / 5;
	if (fdf->map[i][j] != 0)
		bresenham(fdf, puntos, get_rgba(0, fdf->map[i][j] * 10, fdf->map[i][j] * 3, 255));
	else
		bresenham(fdf, puntos, get_rgba(0, 0, 0, 255));
}

void dale_duro(void *param)
{
	t_fdf *fdf;
	int puntos[4];
	int i;
	int j;

	fdf = param;
	i = 0;
	while (i < fdf->fil - 1)
	{
		j = 0;
		while (j < fdf->col - 1)
		{
			dale_duro2(fdf, puntos, i, j);
			dale_duro3(fdf, puntos, i, j);
			j++;
		}
		i++;
	}
}

void fill_map(t_fdf *fdf, char *line, int fil)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	i = 0;
	while (split[i])
	{
		fdf->map[fil][i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	free(split);
}

void	get_map(t_fdf *fdf)
{
	char	*line;
	int		fd;
	int		i;

	fdf->map = (int **)malloc(sizeof(int *) * (fdf->fil + 1));
	i = 0;
	while (i <= fdf->fil)
		fdf->map[i++] = (int *)malloc(sizeof(int) * (fdf->col + 1));
	fd = open(fdf->argv[1], O_RDONLY, 0);
	i = 0;
	while (line = get_next_line(fd))
	{
		fill_map(fdf, line, i);
		i++;
	}
	free(line);
	close(fd);
	fdf->map[i] = NULL;
}

int	get_fil(t_fdf *fdf)
{
	char *line;
	int fd;
	int i;

	fd = open(fdf->argv[1], O_RDONLY);
	i = 0;
	while (line = get_next_line(fd))
	{
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

int ft_wordcount(char *line)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	j = 0;
	while (j < i)
	{
		free(split[j]);
		j++;
	}
	free(split);
	return i;
}

int	get_col(t_fdf *fdf)
{
	char *line;
	int fd;
	int i;

	fd = open(fdf->argv[1], O_RDONLY);
	line = get_next_line(fd);
	i = ft_wordcount(line);
	free(line);
	close(fd);
	return (i);
}

void my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	// Simple up or down detection.
	if (ydelta > 0 && fdf->zoom < 30)
	{
		fdf->zoom++;
		ft_printf("%d", fdf->zoom);
		clear_content(fdf);

		//mlx_delete_image(fdf->mlx, fdf->g_img);
		//mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	}
	else if (ydelta < 0 && fdf->zoom > 1)
	{
		fdf->zoom--;
		ft_printf("%d", fdf->zoom);
		clear_content(fdf);

		//mlx_delete_image(fdf->mlx, fdf->g_img);
		//mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	}
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (argv)
		fdf->argv = argv;
	fdf->fil = get_fil(fdf);
	fdf->col = get_col(fdf);
	ft_printf("fila: %d, columna: %d\n", fdf->fil, fdf->col);
	get_map(fdf);
	fdf->zoom = 2;
	fdf->ang = ANG;
	fdf->width = (fdf->col * fdf->zoom) * cos(fdf->ang) * 2;
	fdf->height = ((fdf->fil * fdf->zoom) * sin(fdf->ang) + (fdf->col * fdf->zoom)) * cos(fdf->ang);
	fdf->mlx = mlx_init(fdf->width, fdf->height, "Fdf by igomez-s", true);
	fdf->g_img = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	mlx_key_hook(fdf->mlx, &check_keypress, (void *)fdf);
	mlx_image_to_window(fdf->mlx, fdf->g_img, 0, 0);
	mlx_scroll_hook(fdf->mlx, &my_scrollhook, fdf);
	mlx_loop_hook(fdf->mlx, &dale_duro, (void *)fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	return (0);
}
