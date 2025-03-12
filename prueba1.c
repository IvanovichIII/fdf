/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:44:21 by igomez-s          #+#    #+#             */
/*   Updated: 2025/03/12 11:54:00 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (fdf->modo == 0)
	{
		puntos[0] = (puntos[0] - puntos[1]) * cos(fdf->ang);
		puntos[1] = (puntos[0] + puntos[1]) * sin(fdf->ang) - fdf->map[i][j];
		puntos[2] = (puntos[2] - puntos[3]) * cos(fdf->ang);
		puntos[3] = (puntos[2] + puntos[3]) * sin(fdf->ang) - fdf->map[i][j + 1];
		puntos[0] += fdf->width / 2 + fdf->horMove;
		puntos[1] += fdf->height / 5 + fdf->verMove;
		puntos[2] += fdf->width / 2 + fdf->horMove;
		puntos[3] += fdf->height / 5 + fdf->verMove;
	}
	else if (fdf->modo == 1)
	{
		puntos[0] = (j * fdf->zoom) + (fdf->map[i][j] * 0.5);
		puntos[1] = (i * fdf->zoom) - (fdf->map[i][j] * 0.5);
		puntos[2] = ((j + 1) * fdf->zoom) + (fdf->map[i + 1][j] * 0.5);
		puntos[3] = (i * fdf->zoom) - (fdf->map[i + 1][j] * 0.5);
		puntos[0] += fdf->width / 10 + fdf->horMove;
		puntos[1] += fdf->height / 10 + fdf->verMove;
		puntos[2] += fdf->width / 10 + fdf->horMove;
		puntos[3] += fdf->height / 10 + fdf->verMove;
	}
	else if (fdf->modo == 2)
	{
		puntos[0] = ((j - i) * fdf->zoom) / (1 + (fdf->map[i][j] * 0)) / 2;
		puntos[1] = ((j + i) * fdf->zoom - fdf->map[i][j] * 2) / (1 + (fdf->map[i][j] * 0)) / 2;
		puntos[2] = (((j + 1) - i) * fdf->zoom) / (1 + (fdf->map[i + 1][j] * 0)) / 2;
		puntos[3] = (((j + 1) + i) * fdf->zoom - fdf->map[i + 1][j] * 2) / (1 + (fdf->map[i + 1][j] * 0)) / 2;
		puntos[0] += fdf->width / 2 + fdf->horMove;
		puntos[1] += fdf->height / 10 + fdf->verMove;
		puntos[2] += fdf->width / 2 + fdf->horMove;
		puntos[3] += fdf->height / 10 + fdf->verMove;
	}
	if ((puntos[1] >= 0 && puntos[3] >= 0) && (puntos[1] < fdf->height && puntos[3] < fdf->height))
		if (j < fdf->col - 1 && i < fdf->fil - 1)
			if (fdf->map[i][j] > 0)
				bresenham(fdf, puntos, get_rgba(fdf->map[i][j] * fdf->colorP, fdf->map[i][j] * fdf->colorS, fdf->map[i][j] * fdf->colorT, 255));
			else if (fdf->map[i][j] < 0)
				bresenham(fdf, puntos, get_rgba(fdf->map[i][j] * fdf->colorT, fdf->map[i][j] * fdf->colorS, fdf->map[i][j] * fdf->colorP, 255));
			else
				bresenham(fdf, puntos, get_rgba(0, 0, 0, 255));
}

void dale_duro3(t_fdf *fdf, int puntos[4], int i, int j)
{
	puntos[0] = j * fdf->zoom;
	puntos[1] = i * fdf->zoom;
	puntos[2] = j * fdf->zoom;
	puntos[3] = i * fdf->zoom + fdf->zoom;
	if (fdf->modo == 0)
	{
		puntos[0] = (puntos[0] - puntos[1]) * cos(fdf->ang);
		puntos[1] = (puntos[0] + puntos[1]) * sin(fdf->ang) - fdf->map[i][j];
		puntos[2] = (puntos[2] - puntos[3]) * cos(fdf->ang);
		puntos[3] = (puntos[2] + puntos[3]) * sin(fdf->ang) - fdf->map[i + 1][j];
		puntos[0] += fdf->width / 2 + fdf->horMove;
		puntos[1] += fdf->height / 5 + fdf->verMove;
		puntos[2] += fdf->width / 2 + fdf->horMove;
		puntos[3] += fdf->height / 5 + fdf->verMove;
	}
	else if (fdf->modo == 1)
	{
		puntos[0] = (j * fdf->zoom) + (fdf->map[i][j] * 0.5);
		puntos[1] = (i * fdf->zoom) - (fdf->map[i][j] * 0.5);
		puntos[2] = ((j + 1) * fdf->zoom) + (fdf->map[i + 1][j] * 0.5);
		puntos[3] = (i * fdf->zoom) - (fdf->map[i + 1][j] * 0.5);
		puntos[0] += fdf->width / 10 + fdf->horMove;
		puntos[1] += fdf->height / 10 + fdf->verMove;
		puntos[2] += fdf->width / 10 + fdf->horMove;
		puntos[3] += fdf->height / 10 + fdf->verMove;
	}
	else if (fdf->modo == 2)
	{
		puntos[0] = ((j - i) * fdf->zoom) / (1 + (fdf->map[i][j] * 0)) / 2;
		puntos[1] = ((j + i) * fdf->zoom - fdf->map[i][j] * 2) / (1 + (fdf->map[i][j] * 0)) / 2;
		puntos[2] = (((j + 1) - i) * fdf->zoom) / (1 + (fdf->map[i + 1][j] * 0)) / 2;
		puntos[3] = (((j + 1) + i) * fdf->zoom - fdf->map[i + 1][j] * 2) / (1 + (fdf->map[i + 1][j] * 0)) / 2;
		puntos[0] += fdf->width / 2 + fdf->horMove;
		puntos[1] += fdf->height / 10 + fdf->verMove;
		puntos[2] += fdf->width / 2 + fdf->horMove;
		puntos[3] += fdf->height / 10 + fdf->verMove;
	}
	if ((puntos[1] >= 0 && puntos[3] >= 0) && (puntos[1] < fdf->height && puntos[3] < fdf->height))
		if (j < fdf->col - 1 && i < fdf->fil - 1)
			if (fdf->map[i][j] > 0)
				bresenham(fdf, puntos, get_rgba(fdf->map[i][j] * fdf->colorP, fdf->map[i][j] * fdf->colorS, fdf->map[i][j] * fdf->colorT, 255));
			else if (fdf->map[i][j] < 0)
				bresenham(fdf, puntos, get_rgba(fdf->map[i][j] * fdf->colorT, fdf->map[i][j] * fdf->colorS, fdf->map[i][j] * fdf->colorP, 255));
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
	/*mlx_get_mouse_pos(fdf->mlx, &fdf->xMouse, &fdf->yMouse);
	ft_printf("x: %d, y: %d\n", fdf->xMouse, fdf->yMouse);*/
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
	//fdf->map[i] = NULL;
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

void clear_content(t_fdf *fdf)
{
	fdf->width = fmax(100, fabs((fdf->col + fdf->fil) * fdf->zoom * cos(fdf->ang)));
	fdf->height = fmax(100, fabs((fdf->col + fdf->fil) * fdf->zoom * sin(fdf->ang) * 0.8));
	mlx_delete_image(fdf->mlx, fdf->g_img);
	fdf->g_img = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	mlx_image_to_window(fdf->mlx, fdf->g_img, 0, 0);
}

void check_keypress(mlx_key_data_t key, void *param)
{
	t_fdf *fdf;

	fdf = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(fdf->mlx);
	if (key.key == MLX_KEY_M && key.action == MLX_PRESS)
	{
		if (fdf->modo >= 3)
			fdf->modo = 0;
		else
			fdf->modo++;
		fdf->horMove = 0;
		fdf->verMove = 0;
		clear_content(fdf);
	}
	if (key.key == MLX_KEY_UP && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
	{
		fdf->verMove -= 1 * fdf->zoom;
		clear_content(fdf);
	}
	if (key.key == MLX_KEY_DOWN && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
	{
		fdf->verMove += 1 * fdf->zoom;
		clear_content(fdf);
	}
	if (key.key == MLX_KEY_RIGHT && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
	{
		fdf->horMove += 1 * fdf->zoom;
		clear_content(fdf);
	}
	if (key.key == MLX_KEY_LEFT && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
	{
		fdf->horMove -= 1 * fdf->zoom;
		clear_content(fdf);
	}
	if (key.key == MLX_KEY_C && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
	{
		fdf->colorP += 7;
		fdf->colorS += 3;
		fdf->colorT += 1;
		clear_content(fdf);
	}
}

void my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (ydelta > 0 && fdf->width < 5000)
	{
		fdf->zoom++;
		ft_printf("%d", fdf->zoom);
		clear_content(fdf);
	}
	else if (ydelta < 0 && fdf->zoom > 1)
	{
		fdf->zoom--;
		ft_printf("%d", fdf->zoom);
		clear_content(fdf);
	}
}
/*void cursor_hook(double cursor_x, double cursor_y, void *param)
{
	t_FdF *s;
	t_vec2 distance;

	s = param;
	s->clicked = 0;
	if (!mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTON_LEFT) && !mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTON_MIDDLE) && !mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTON_RIGHT))
		return;
	distance.x = cursor_x - s->initial_cursor_pos.x;
	distance.y = cursor_y - s->initial_cursor_pos.y;
	if (mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTON_MIDDLE))
		s->height_scale -= (double)distance.y / 500;
	if (mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTON_RIGHT))
		set_rotation(distance, s);
	if (mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		if (!s->orthographic)
			distance = (t_vec2){distance.x * 3.3333, distance.y * 3.3333};
		s->mesh_pos.x += distance.x;
		s->mesh_pos.y += distance.y;
	}
	if (CURSOR_SETTABLE)
		mlx_set_mouse_pos(s->mlx, s->initial_cursor_pos.x, s->initial_cursor_pos.y);
	else
		s->initial_cursor_pos = (t_ivec2){cursor_x, cursor_y};
}*/
void ratoncito(int x, int y, void *param)
{
	t_fdf *fdf;
	int	*a;
	int	*b;

	fdf = param;
	// mlx_set_mouse_pos(fdf->mlx, fdf->initial_cursor_pos.x, fdf->initial_cursor_pos.y);
	mlx_get_mouse_pos(fdf->mlx, a, b);
	ft_printf("x: %d, y: %d\n", a, b);
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
	fdf->zoom = 1;
	fdf->modo = 0;
	fdf->ang = ANG;
	fdf->colorP = 10;
	fdf->colorS = 2;
	fdf->width = fmax(100, fabs((fdf->col + fdf->fil) * fdf->zoom * cos(fdf->ang)));
	fdf->height = fmax(100, fabs((fdf->col + fdf->fil) * fdf->zoom * sin(fdf->ang) * 0.8));
	fdf->mlx = mlx_init(fdf->width, fdf->height, "Fdf by igomez-s", true);
	fdf->g_img = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	mlx_key_hook(fdf->mlx, &check_keypress, (void *)fdf);
	mlx_image_to_window(fdf->mlx, fdf->g_img, 0, 0);
	mlx_scroll_hook(fdf->mlx, &my_scrollhook, fdf);
	mlx_loop_hook(fdf->mlx, &dale_duro, (void *)fdf);
	//mlx_cursor_hook(fdf->mlx, &ratoncito, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	free(fdf);
	return (0);
}
